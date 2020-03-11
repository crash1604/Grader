#include "../hdr/Course.h"

Course::Course()
{
	title="";
	category="";
	maxMarks=0;
	weight=0;

}


Course::Course(char &title, char &category, int maxmarks, int weight)
{
	title=title;
	category=category;
	maxMarks=maxmarks;
	weight=weight;
}


