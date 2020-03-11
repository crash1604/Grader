WARNINGS= -Wall -Wextra

all: obj/main.o obj/Student.o obj/Course.o obj/exists.o
	g++ $(WARNINGS) obj/main.o obj/Student.o obj/exists.o obj/Course.o -o bin/grader

obj/main.o: hdr/Course.h hdr/Student.h src/main.cpp src/Student.cpp src/Course.cpp src/exists.cpp hdr/exists.h
	g++ $(WARNINGS) -c src/main.cpp -o obj/main.o

obj/Student.o: hdr/Student.h hdr/Course.h src/Student.cpp
	g++ $(WARNINGS) -c src/Student.cpp -o $@

obj/Course.o: hdr/Course.h hdr/Student.h src/Course.cpp
	g++ $(WARNINGS) -c src/Course.cpp -o $@
obj/exists.o: hdr/exists.h src/exists.cpp
	g++ $(WARNINGS) -c src/exists.cpp -o $@
clean:
	rm bin/*
	rm obj/*
	rm objd/*
