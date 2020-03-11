#! /bin/bash

# default file/directory names
prog="./driverx"
indir="test/"
expdir="test/expOut"
resdir="test/results"

# default limits on cpu seconds and chars of output to store
cpu=10
climit=1000

# ensure we have a results directory
mkdir -p ${resdir}

# display time/date of run
echo "Tests run on"
date

# run on each test file in the test directory
for tfile in ${indir}/* ; do

    # get the name of the expected output file
    fname=$(basename ${tfile} )

    # get the names of the expected output and actual results files
    efile="${expdir}/${fname}"
    ofile="${resdir}/${fname}"

    # create a temp file for the differences between actual and expected
    dfile=$(mktemp)

    # run the actual test
    (ulimit -t  ${cpu}; (${prog} < ${tfile} 2>&1 | head -c ${climit} > ${ofile}))

    # run the test again without capturing output, just to check the return value
    (ulimit -t  ${cpu}; (${prog} < ${tfile} 2>&1 > /dev/null || echo " ** gave non-zero exit status"))

    # use diff to check output correctness
    difv=0
    (((diff ${ofile} ${efile} 2>&1 > ${dfile}) && (echo "${tfile} passed")) || (echo "${tfile} failed") )

done

