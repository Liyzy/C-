#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double a=0,double b=0){real=a;imag=b;}
    ~Complex(){}
    Complex operator+(const Complex &C);
    Complex operator-(const Complex &C);
    Complex operator*(const Complex &C);
    Complex operator/(const Complex &C);
    friend ostream& operator<<(ostream& out,Complex &C);
};
Complex Complex::operator+(const Complex &C)
{
    Complex tc;
    tc.real=real+C.real;
    tc.imag=imag+C.imag;
    return tc;
}
Complex Complex::operator-(const Complex &C)
{
    Complex tc;
    tc.real=real-C.real;
    tc.imag=imag-C.imag;
    return tc;
}
Complex Complex::operator*(const Complex &C)
{
    Complex tc;
    tc.real=real*C.real-imag*C.imag;
    tc.imag=real*C.imag+imag*C.real;
    return tc;
}
Complex Complex::operator/(const Complex &C)
{
    Complex tc;
    tc.real=(real*C.real+imag*C.imag)/(C.real*C.real+C.imag*C.imag);
    tc.imag=(imag*C.real-real*C.imag)/(C.real*C.real+C.imag*C.imag);
    return tc;
}
ostream& operator<<(ostream&out,Complex&C)
{
    if(C.imag>=0)
      out<<C.real<<"+"<<C.imag<<"i\n";
    else
        out<<C.real<<C.imag<<"i\n";
    return out;
}
int main()
{
    Complex c1(3,4),c2(5,7),ans1,ans2,ans3,ans4; //自己定义C1,C2
    ans1=c1+c2;
    ans2=c1-c2;
    ans3=c1*c2;
    ans4=c1/c2;
    cout<<"c1+c2= "<<ans1;
    cout<<"c1-c2= "<<ans2;
    cout<<"c1*c2= "<<ans3;
    cout<<"c1/c2= "<<ans4;
    return 0;
}
