#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public :
    ~Time();
    Time(int h=0,int m=0,int s=0)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void setClock(int h, int m, int s);    //用来设置时、分、秒
    void setClock (int h, int m);        //用来设置时、分
    void setClock (int h);
    void tick()
    {
        if(second+1==60)
        {
            minute+=1;
            second=0;
            if(minute==60)
            {
                hour+=1;
                minute=0;
            }
        }
        else
            second+=1;
        std::cout<<"New time:\n"<<hour<<" "<<minute<<" "<<second<<endl;
    }
    void disp()
    {
        std::cout<<"Time is:\n"<<hour<<" "<<minute<<" "<<second<<endl;
    }
};
void Time::setClock(int h,int m,int s)
{

    hour=(h>=0&&h<=23)?h:0 ;
    minute=(m>=0&&m<=59)?m :0 ;
    second=(s>=0&&s<=59)?s:0 ;
}
void Time::setClock(int h,int m)
{
    hour=(h>=0&&h<=23)?h:0 ;
    minute=(m>=0&&m<=59)?m:0 ;
}
void Time::setClock (int h)
{
    hour=(h>=0&&h<=23)?h:0 ;
}
Time::~Time()
{
    cout<<"Time has been destructed\n";
}
int main()
{
    Time T1;
    T1.setClock(13,59,59);
    T1.disp();
    T1.tick();
    T1.setClock(21);
    T1.disp();
    return 0;
}
