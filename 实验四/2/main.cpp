/*定义一个类Safearray继承自averarray和revarray，并保证访问数组不会越界。
在继承过程中声明为虚基类，体会虚基类在解决二义性中的问题中的作用。调试中可以试一试不用虚基类出现的问题。*/

#include <iostream>

using namespace std;
class myarray
{
protected:
    int* arr;
    int leng;
    int moni;
public:
    myarray(int leng,int m);
    ~myarray();
    void input();
};
myarray::myarray(int length,int m)
{
    std::cout<<"Input the number:";
    std::cin>>length;
    leng=length;
    moni=m;
    arr=new int[length];
    std::cout<<"base constructing...\n";
}
myarray::~myarray()
{
    delete []arr;
    std::cout<<"base destructing...\n";
}
void myarray::input()
{
    int i;
    for(i=0; i<leng; i++)
        std::cin>>arr[i];
}
class revarray:virtual public myarray
{
protected:
    int* revarr;
    int moni;
public:
    revarray(int l=0,int* r=NULL,int m1=0,int m2=0):myarray(l,m1)
    {
        revarr=new int[leng];
        moni=m2;
        std::cout<<"derived constructing...\n";
    }
    ~revarray()
    {
        delete []revarr;
        std::cout<<"\nderived destructing...";
    }
    void rev();
    void disp();
};
void revarray::rev()
{
    revarr=new int[leng];
    int i,j;
    for(i=leng-1,j=0; i>=0; i--,j++)
        revarr[j]=arr[i];
}
void revarray::disp()
{
    int i;
    for(i=0; i<leng; i++)
        std::cout<<revarr[i]<<' ';
}
class averarray : virtual public myarray
{
protected:
    double average;
    int moni;
public:
    averarray(int len = 0, double average = 0.0,int n1=0,int n2=0) : myarray(len,n1)
    {
        this->average = average;
        moni=n2;
        cout << "p constructing...\n";
    }
    ~averarray()
    {
        cout <<endl << "p bye.\n";
    }
    void getaver();
};

void averarray::getaver()
{
    int sum = 0;
    int i;
    for (i = 0; i < leng; i++)
        sum += *(arr + i);
    cout<<endl<<"average is "<<(double)sum / leng<<endl;
}
class safearray:public averarray,public revarray
{
    int moni;
public:
    safearray(int x,int y,int z,int s,int y1=0,int z1=0,int l1=0, int l3=0,double d=0.0,int rl=0,int* r=NULL):myarray(l1,x),revarray(rl,r,y1,y),averarray(l3,d,z1,z)
    {
        moni=s;
        cout<<"safe class constructing...\n";
    }
    ~ safearray()
    {
        cout<<"safe class destructing...";
    }
    void test();
    void show();
};
void safearray::test()
{
    cout<<"the location you want to check:";
    int location;
    cin>>location;
    if(location>leng)
        cout<<"Error!\n";
    else
    {
        cout<<*(arr+location-1)<<endl;
    }
}
void safearray::show()
{
    cout<<myarray::moni<<endl;
    cout<<revarray::moni<<endl;
    cout<<averarray::moni<<endl;
    cout<<safearray::moni<<endl;
}
int main()
{

    safearray s(1,2,3,4);
    s.input();
    s.rev();
    s.disp();
    s.getaver();
    s.test();
    s.show();
    return 0;
}
