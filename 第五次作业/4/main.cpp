/*4.	定义一个类Nawarray继承自averarray和revarray。
在继承过程中声明为虚基类，体会虚基类在解决二义性中的问题中的作用。调试中可以试一试不用虚基类出现的问题。*/

#include <iostream>

using namespace std;
class Array
{
protected:
    int x;
public:
    Array(int x){this->x=x;cout<<"Array constructing...\n";}
    ~Array(){cout<<"Array destructing...\n";}
    void disp(){cout<<"X="<<x<<endl;}
};
class averarray:virtual public Array
{
protected:
    int x;
public:
    averarray(int m,int n):Array(m){x=n;cout<<"avararray constructing...\n";}
    ~averarray(){cout<<"averarray destructing...\n";}
    void disp(){cout<<"AX="<<x<<endl;}
};
class revarray:virtual public Array
{
protected:
    int x;
public:
    revarray(int j,int k):Array(j){x=k;cout<<"revarray constructing...\n";}
    ~revarray(){cout<<"revarray destructing...\n";}
    void disp(){cout<<"RX="<<x<<endl;}
};
class Nawarray:public averarray,public revarray
{
    int x;
public:
    Nawarray(int a,int b,int c,int d,int e,int f):Array(d),averarray(a,e),revarray(b,f)
    {
        x=c;
        cout<<"Nawarray constructing...\n";
    }
    ~Nawarray(){cout<<"Nawarray destructing...\n";}
    void disp()
    {
        cout<<"X="<<Nawarray::x<<endl;
        cout<<"X="<<revarray::x<<endl;
        cout<<"X="<<averarray::x<<endl;
        cout<<"X="<<Array::x<<endl;
    }
};
int main()
{
    Nawarray n(1,2,3,4,5,6);
    n.disp();
    return 0;
}
