#include<iostream> 
using namespace std; 
class voting 
{ 
 int a[10]; 
 int sb=0; 
 int choice,bjp=0,inc=0,aap=0,tmc=0,others=0;; 
 public: 
 void display(); 
}; 
 void voting::display() 
 { 
 for(int i=0; i<10; i++) 
 { 
 cout<<"\n enter your votes for one of the five parties mentioned below: ";  cout<<"\n 1 for BJP \n 2 for CONGRESS \n 3 for AAP \n 4 for TMC \n 5 for OTHERS : \n";  cin>>a[i]; 
 } 
 for(int i=1;i<11;i++) 
 { 
 if(a[i]==1) 
 { 
 bjp++; 
 } 
 else if(a[i]==2) 
 { 
 inc++; 
 } 
 else if(a[i]==3) 
 { 
 aap++; 
 } 
 else if(a[i]==4) 
 { 
 tmc++; 
 } 
 else if(a[i]==5) 
 { 
 others++; 
 } 
 else if(a[i]!=1&&a[i]!=2&&a[i]!=3&&a[i]!=4&&a[i]!=5) 
 { 
 sb+=1; 
 }} 
 cout<<" \n votes for bjp: "<<bjp;
 cout<<" \n votes for aap: "<<aap; 
 cout<<" \n votes for inc: "<<inc; 
 cout<<" \n votes for tmc: "<<tmc; 
 cout<<" \n votes for other: "<<others; 
 cout<<" \n votes for spoilt ballots: "<<sb; 
 if(bjp>aap&&bjp>inc&&bjp>tmc&&bjp>others)  {cout<<"\n THE WINNER IS : BJP ";} 
 else if(aap>bjp&&aap>inc&&aap>tmc&&aap>others)  { cout<<"\n THE WINNER IS : AAP ";} 
 else if(inc>bjp&&inc>aap&&inc>tmc&&inc>others)  { cout<<"\n THE WINNER IS : INC ";} 
 else if(tmc>aap&&tmc>bjp&&tmc>inc&&tmc>others)  { cout<<"\n THE WINNER IS : TMC ";} 
 else if(others>bjp&&others>aap&&others>tmc&&others>inc)  { cout<<"\n THE WINNER IS : OTHERS ";} 
  
  
 } 
 int main() 
 { voting obj; 
 obj.display(); 
 }
