#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include "../hdr/Course.h"
#include "../hdr/Student.h"
#include "../hdr/exists.h" 
using namespace std;

double round(double var) 
{ 
    double value = (int)(var * 100 + .5); 
    return (double)value / 100; 
}
const char* getGrade(double Score)
{
	const char* G;
	if(Score>=90)
	G= "A+";
	else if(Score < 90 && Score >=85)
	G= "A ";
	else if(Score <85 && Score>=80)
	G= "A-";
	else if(Score < 80 && Score>=76)
	G= "B+";
	else if(Score < 76 && Score>=72)
	G= "B ";
	else if(Score < 72 && Score>=68)
	G= "B-";
	else if(Score < 68 && Score>=64)
	G= "C+";
	else if(Score < 64 && Score>=60)
	G= "C ";
	else if(Score < 60 && Score>=55)
	G= "C-";
	else if(Score < 55 && Score>=50)
	G= "D ";
	else
	G= "F ";
        return G;

}
int CountStudent(std::string &name)
{
	int counter=0;
    ifstream inFile(name);
	string line;
	 while(getline(inFile,line,'\n')) //count number of lines in the file
		{
			stringstream s(line);
			string name;
			s>>name;
			if(isWord(name))
  			counter++;
			
		}
	return counter;
}




int main(int argc, char** argv)
{
 cout<<system("date");
 string paths;
 string opt="-s";
 int searchflag=0;
 string studentSearch;
 if(argc==1)
 {
 cout<<"please enter path to file:-\n";
 cin>>paths;
 }
 else if(argc==2) //checks for --s command
 {

  paths=argv[1];

 }
 else if(argc==3)//checks for --s command
 {
  if (opt.compare(argv[1])==0)
  {
	  studentSearch = argv[2];
	  searchflag=1;
  }
  cout<<"Please enter  the path for the file: - \n";
  cin>>paths;
 }
 else if(argc ==4)
 {
	 if(opt.compare(argv[1])==0)
  {
   studentSearch= argv[2];
   paths=argv[3];
   searchflag=1;   
  }
  else if(opt.compare(argv[2])==0)
  {
	paths=argv[1];
	studentSearch=argv[3];
	searchflag=1;	
  }
 } 
 else{
 cout<<"Error::inappropriate parameters\nEXITING THE PROGRAM\n";
 system("exit");
}



if(exists(paths)){
	cout<<"opening the  file at location "<<paths<<endl;
     fileCheck(paths);

}
else
{
 cout<<"ERROR:invalid file name\nExiting prgram\n";
 system("exit");
}

  
  
 int nos=CountStudent(paths);
 //data about fiel variables is neglected.
cout<<nos<<" is number of students\n";
 



 

 Student students[nos];

 //initializing student class with a specific number of elements 
 //size of array is also specified with parameterized constructor


 Course courses[8];
 //initializing courses class with specific number of elements


 ifstream inputFile(paths);

 string loader;
 //this string will load the values 


 int StudentID=0; 





//do getline while loop once, to get total number of lines,
//subtract header to get studetns
//do this while loop for header as a for loop
//do for loop for students
 while(getline(inputFile,loader))
//loads the values into files required
 {
	

 stringstream str(loader);
 string temp;


   str>>temp;

  

  if( temp[0]=='#' || temp[0]=='\0'|| temp[0]=='0' ){

   getline(str, temp);
	//ignores the commented line



                    }
  else if( temp.compare("TITLE")==0 )
   {//storing title for the event
    for( int i = 0; i < 8; i++)
	{
	 str>>courses[i].title;
	}
   }


   else if(temp.compare("CATEGORY")==0)
   {//storing categories
	for(int i=0;i<8;i++)
	{
	 str >> courses[i].category;
	}
   }


   else if( temp.compare("MAXMARK") == 0 )
   {//storing data of MAximum marks
	for(int i = 0; i < 8; i++)
	{
	 str>>courses[i].maxMarks;
	}
   }


   else if(temp.compare("WEIGHT")==0)
   {//storing data of weight
	for(int i = 0; i < 8; i++)
	{
	 str>>courses[i].weight;
	}
   }


//for loop based on number of students
//use the else to count number of students
   else //storing data of students
   {

	string check;
		if(isWord(temp)){
		    students[StudentID].StudentName = temp;
		    for(int i = 0; i < 8; i++){
		str>>check;
    if(check.compare("WDR")==0){
    getline(str, check);
    students[StudentID].FinalScore=0;
    students[StudentID].StudentName+=" *WDR*";
    }	
    else{
           stringstream filter(check);	    
		    filter>>students[StudentID].AttainedMarks[i];
    }
		 
			 }

	
		    StudentID++;

		  }
    }

 }


 int i=0;
 while( i <nos)
 {

  
students[i].FinalScore=0;


  for(int j=0;j<8;j++)
  {
	
  students[i].FinalScore += ((students[i].AttainedMarks[j]/courses[j].maxMarks)* courses[j].weight );



  }
	i++;
 }
   string lab="Lab";

   string Midt="Midterm";
   int Midind;
   string finalE="Final";
   int finalind;
   int labind[4];
   int indcounter=0;

      	for(int i=0;i<8;i++)
   	{
   		if(lab.compare(courses[i].category)==0)
		{
			labind[indcounter]=i;
			indcounter++;
		}
		else if(Midt.compare(courses[i].category)==0)
		{
			Midind=i;

		}
		else if(finalE.compare(courses[i].category)==0)
		{
			finalind=i;
		}
   	}
   
  

cout<<"Student\tLab\tMidterm\tFinal\tTotal\tGrade\n";




if(searchflag==0)
{
 for(int i=0;i<nos;i++)
 { 
	double labTot=0;
	for(int k=0;k<4;k++)
	{
	    labTot+=students[i].AttainedMarks[labind[k]];
	}
	labTot=labTot/4;
	cout<<students[i].StudentName<<"\t";
	cout<<labTot<<"\t";
	cout<<round(students[i].AttainedMarks[Midind])<<"\t";
	cout<<round(students[i].AttainedMarks[finalind])<<"\t";
	cout<<round(students[i].FinalScore);
	cout<<"\t"<<getGrade(round(students[i].FinalScore))<<"\t";
 	if(students[i].FinalScore<=50 && students[i].FinalScore>=49.45)
	{
		cout<<"*******WARNING:NEAR FAIL:**********\t";
	}
	cout<<endl;
}
}
else
{
   for(int i=0;i<nos;i++)
   {
   	if(studentSearch.compare(students[i].StudentName)==0)
	{
		
		
		double labTot=0;
		for(int k=0;k<4;k++)
		{
			labTot+=students[i].AttainedMarks[labind[k]];
		}
		labTot=labTot/4;
		cout<<students[i].StudentName<<"\t";
	        cout<<round(labTot)<<"\t";
	        cout<<round(students[i].AttainedMarks[Midind])<<"\t";
	        cout<<round(students[i].AttainedMarks[finalind])<<"\t";

		cout<<round(students[i].FinalScore);
		cout<<"\t"<<getGrade(round(students[i].FinalScore));
		if(students[i].FinalScore<=50 && students[i].FinalScore>=49.45)
		{
			cout<<"*******WARNING:NEAR FAIL:**********\t";
		}
		cout<<endl;

	
	}
   }
}


return 0;

}

























