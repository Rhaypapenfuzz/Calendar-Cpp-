//My Simple Calendar
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int getYear();
int getStartingDay();
void printHeading(int);
string readMonthName();
int readNumDays();
int printMonth(int,int,string);
void formatting(int);
int year, numOfDays, startDate, lastDay;
string  monthName;
//const string pathfile = "infile.txt";
ifstream infile;

int main() {
getYear();
getStartingDay();
printHeading(year);
readMonthName();
infile.close();
return 0;
}


int getYear()
{
 cout<<"Enter the  Year:\n";
 cin>>year;
return year;
}
int getStartingDay()
{
  cout<<"Enter the start date <0 = Sun, 1 = Mon, "
  <<"2 = Tues,\n3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat>:\n";
  cin>>startDate;
  return startDate;
}
void printHeading(int year)
{

cout<<"\t\tYEAR -- "<< year <<"\n\n\n";
}
string readMonthName()
{ 
  int count = 0;
	infile.open("infile.txt");
  while(count<12)
  {
      count++;
        infile >> monthName; 
        printMonth(startDate, readNumDays(),monthName);
        
    }

  return monthName;
}

int readNumDays()
{

  infile>>numOfDays;
  
  return numOfDays;
}


int printMonth(int firstDay,int numOfDays,string monthName)
{
lastDay = (startDate + numOfDays)%7;
cout<<"\t\t"<<  monthName<<endl
<<"Sun:\tMon:\tTue:\tWed:\tThu:\tFri:\tSat:"<<endl;
formatting(firstDay);
startDate = lastDay;
//daysLeft= (startDate + numOfDays)%7; 
for(int date=1;date<=numOfDays;date++)
{
  if(date>1 && (date+firstDay)%7 == 1)
  { 
    cout<<endl;
    cout<< date <<"\t";
  }
  else
  {

  cout<< date <<"\t";
  }
}
cout<<"\n\n";
return lastDay;
}

void formatting(int startDate)
{
switch(startDate)
  {
  case 1: cout<<"\t";
  break; 
  case 2: cout<<"\t\t";
  break; 
  case 3: cout<<"\t\t\t";
  break; 
  case 4: cout<<"\t\t\t\t";
  break; 
  case 5: cout<<"\t\t\t\t\t";
  break; 
  case 6: cout<<"\t\t\t\t\t\t";
  break; 
  default:
  break; 
  }
}
