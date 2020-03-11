#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string.h>
#include "Course.h"
#include<sstream>

class Student
{
 public:
  std::string StudentName;
  double AttainedMarks[7];
  double FinalScore;
 public:
  Student();
  Student(char& Name);
  
};

#endif
