#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string.h>
#include "Student.h"

class Course
{
	public:
	std::string title;
	std::string category;
	double maxMarks;
	int weight;

	public:
		Course();
		Course(char &title, char &category, int maxmarks, int weight);
};

#endif
