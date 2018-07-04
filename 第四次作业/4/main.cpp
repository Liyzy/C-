/*定义描述时间的Time类，包括数据成员小时hour、分钟minute和秒second，定义相关函数实现如下操作：
1）重载运算符“+”与“-”，能够实现时间对象与整数秒的加减操作。
2）重载运算符“<<”输出时间对象，能够按照“小时：分钟：秒”的方式显示时间。
3）重载运算符“++”与“--”，要求能够实现时间的合理自增自减功能(秒数的增减)。*/


#include <iostream>
#include <cmath>
using namespace std;

class Time
{
private:
    int hour,minute,second;
public:
    Time() {};
    Time(int h,int m,int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    Time operator+(int s);
    Time operator-(int s);
    Time operator++();
    Time operator--();
    void show()
    {
        cout<<"Time is "<<hour<<":"<<minute<<":"<<second<<endl;
    }
    friend ostream& operator<<(ostream& out,Time& t);
} ;
Time Time::operator+(int s)
{
    Time t;
    t.second=(second+s)%60;
    t.minute=(minute+((second+s)/60))%60;
    t.hour=hour+((minute+((second+s)/60))/60);
    return t;
}
Time Time::operator-(int s)
{
    Time t;
    t.second=(second-s)%60;
    if(t.second<0)
    {
        t.second=60+t.second;
        if(t.minute==0)
        {
            t.minute=59;
            t.hour=hour-1;
        }
        else
            t.hour=hour;
        t.minute=minute-1;
    }
    else
    {
        t.minute=minute;
        t.hour=hour;
    }
    return t;
}
ostream& operator<<(ostream& out,Time& t)
{
    out<<t.hour<<":"<<t.minute<<":"<<t.second<<endl;
    return out;
}
Time Time::operator++()
{
    Time t;
    t.second=(second+1)%60;
    t.minute=(minute+((second+1)/60))%60;
    t.hour=hour+((minute+((second+1)/60))/60);
    return t;
}
Time Time::operator--()
{
    Time t;
    t.second=(second-1)%60;
    if(t.second<0)
    {
        t.second=60+t.second;
        if(t.minute==0)
        {
            t.minute=59;
            t.hour=hour-1;
        }
        else
            t.hour=hour;
        t.minute=minute-1;
    }
    else
    {
        t.minute=minute;
        t.hour=hour;
    }
    return t;
}
int main()
{
    cout << "Input time:\n";
    int h,m,s,As,Ss;
    cin>>h>>m>>s;
    Time t1(h,m,s);
    cout<<"Add second:";
    cin>>As;
    t1=t1+As;
    cout<<t1;
    cout<<"Subtract second:";
    cin>>Ss;
    t1=t1-Ss;
    cout<<t1;
    cout<<"自增1秒为:\n";
    t1=++t1;
    cout<<t1;
    cout<<"自减1秒为:\n";
    t1=--t1;
    cout<<t1;
    return 0;
}
