/*有一个交通工具类vehicle，将它作为基类派生小车类car、卡车类truck和轮船类boat，定义这些类并定义一个虚函数用来显示各类信息。*/

#include <iostream>

using namespace std;
class vehicle
{
public:
    vehicle()
    {
        cout<<"vehicle class constructing...\n";
    }
    ~vehicle()
    {
        cout<<"vehicle class destructing...\n";
    }
    virtual void disp()
    {
        cout<<"This is a vehicle class.\n";
    }
};
class car:public vehicle
{
public:
    car()
    {
        cout<<"car class constructing...\n";
    }
    ~car()
    {
        cout<<"car class destructing...\n";
    }
    void disp()
    {
        cout<<"This is a car class.\n";
    }
};
class truck:public vehicle
{
public:
    truck()
    {
        cout<<"truck class constructing...\n";
    }
    ~truck()
    {
        cout<<"truck class destructing...\n";
    }
    void disp()
    {
        cout<<"This is a truck class.\n";
    }
};
class boat:public vehicle
{
public:
    boat()
    {
        cout<<"boat class constructing...\n";
    }
    ~boat()
    {
        cout<<"boat class destructing...\n";
    }
    void disp()
    {
        cout<<"This is a boat class.\n";
    }
};
int main()
{
    vehicle* v[3];
    car c;
    truck t;
    boat b;
    v[0]=&c;
    v[1]=&t;
    v[2]=&b;
    for(int i=0; i<3; i++)
        v[i]->disp();
    return 0;
}
