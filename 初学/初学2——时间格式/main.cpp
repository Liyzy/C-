#include<iostream>
using namespace std;
void time(int hours,int minutes)
{
    cout<<"Time:"<<hours<<":"<<minutes;
}
int main()
{
     int hours,minutes;
     cout<<"Enter the number of hours:";
     cin>>hours;
     cout<<"Enter the number of minutes:";
     cin>>minutes;
     void time(int hours,int minutes);
     time(hours,minutes);
     return 0;
}
