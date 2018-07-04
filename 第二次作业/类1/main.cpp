#include <iostream>

using namespace std;

class Time
{
     int hour;
     int minute;
     int second;
 public:
    void modify(Time & T2,int hour,int minute,int second );
    void show();
    Time(int h,int m,int s):hour(h),minute(m),second(s){}
};
void Time::modify(Time & T2,int hour,int minute,int second)
{
    if(hour<=23&&hour>=0&&minute<=59&&minute>=0&&second<=59&&second>=0)
   {
     T2.hour=hour;
     T2.minute=minute;
     T2.second=second;
   }
    else
        std::cout<<"Error!";
}
void Time::show()
{
    std::cout<<hour<<" "<<minute<<" "<<second<<endl;
}
int main()
{
    int hour_,minute_,second_;
    Time T1(17,26,6);
    Time & T2=T1;
    T1.show();
    std::cout <<"Input new time:\n";
    std::cin>>hour_>>minute_>>second_;
    T1.modify(T2,hour_,minute_,second_);
    T1.show();
    return 0;
}
