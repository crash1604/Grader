#include "../hdr/exists.h"

bool exists(const string& name)
{
  if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }

}

bool is_number(const std::string& s)
{
	char* end = 0;
	    double val = strtod(s.c_str(), &end);
	        return end != s.c_str() && *end == '\0' && val != 1000;

	/*
	 * snippet taken from
	 * https://stackoverflow.com/questions/29169153/how-do-i-verify-a-string-is-valid-double-even-if-it-has-a-point-in-it
	 *
	 *
	 *  */
}


bool isWord(const string &str)
{
bool word=false;
int len=str.length();
	for(int i=0;i<len;i++)
	{
		if( ( str[i]>='a' && str[i]<='z') ||( str[i]>='A' && str[i]>='Z') || (str[i]>='0' && str[i]<='9') )
			word = true;
	}
return word;
}


void fileCheck(const string& file)
{
    ifstream i(file);
    string check;
    int keyCount=0;//counts keywords
    int ComCount=0;//counts comment
    int stuCount=0;//counts student
    int checkList[4]={0,0,0,0};//binary true or false for countedkeywords
    /*
     *checkList[0]:- signifies Title
     *checkList[1]:- signifies category
     *checklist[2]:- signifies MaxMarks
     *checkList[3]:- signifies Weight
     *think of this array as an array of parity bits to check the validity of data
     *
     * 	*/
    int fileCounter= 1;//line numbers of the file

    while(getline(i,check))
    {
        stringstream s(check);

	string temp;

	s>>temp;//loads and compares word by word

	if( temp[0]=='#' || temp[0]=='\0' )
	{
		++ComCount;
		getline(s, temp);
	}

	else if ( temp.compare("TITLE")==0  )
	{
 	 ++keyCount;
	 checkList[0]=1;
	}
	else if( temp.compare("CATEGORY")==0)
	{
	 ++keyCount;
	 checkList[1]=1;

	} 
	else if( temp.compare("MAXMARK")==0)
	{
 	 ++keyCount;
	   	for(int i=0;i<8;i++)
	   {
	     s>>temp;
	     if(!is_number(temp))
	     {
	       std::cout<<"Error in input file:line"<<fileCounter<<endl;
	      	std::cout<<check<<endl;
	       exit(0);
 
	     }
		checkList[2]=1;
           }
}
	else if( temp.compare("WEIGHT")==0)
	{
	     ++keyCount;	
	     for(int i=0;i<8;i++)
	     {  
	      s>>temp;
	      if(!is_number(temp))
	      {
	        std::cout<<"Error in input file:line"<<fileCounter<<"\nnot a number in the file\n";
	        	std::cout<<check<<endl;
	       exit(0);

	      }
	      checkList[3]=1;
 
	    }
	}
       
	else if (isWord(temp))
	{
		stuCount++;
           for(int i=0;i<8;i++)
	   {
	     s>>temp;
	     if(is_number(temp) || temp.compare("WDR")==0)
	     { /* this isnt supposed to do anything but just to avoid getting in right loop and conditions*/ }
	     else{
		std::cout<<"Error in input file:line"<<fileCounter<<endl;
	 	std::cout<<check<<endl;
	       exit(0);
    }
		
           }

	 
	}

        ++fileCounter;
    



    }
    if(checkList[0]==0)
    {
    cout<<"FileError: Misssing KeyWord TITLE\n";
    exit(0);
    }
    else if(checkList[1]==0)
    {
    cout<<"FileError: Missing KeyWord CATEGORY\n";
    exit(0);
    }
    else if(checkList[2]==0)
    {
	    cout<<"FileError: Missing KeyWord MAXMARKS\n";
	    exit(0);
    }
    else if(checkList[3]==0)
    {
	    cout<<"FileError: Missing KeyWord WEIGHT\n";
	    exit(0);
    }
}
