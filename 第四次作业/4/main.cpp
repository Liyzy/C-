/*��������ʱ���Time�࣬�������ݳ�ԱСʱhour������minute����second��������غ���ʵ�����²�����
1�������������+���롰-�����ܹ�ʵ��ʱ�������������ļӼ�������
2�������������<<�����ʱ������ܹ����ա�Сʱ�����ӣ��롱�ķ�ʽ��ʾʱ�䡣
3�������������++���롰--����Ҫ���ܹ�ʵ��ʱ��ĺ��������Լ�����(����������)��*/


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
    cout<<"����1��Ϊ:\n";
    t1=++t1;
    cout<<t1;
    cout<<"�Լ�1��Ϊ:\n";
    t1=--t1;
    cout<<t1;
    return 0;
}
