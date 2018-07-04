#include <iostream>
#include<cmath>

using namespace std;

class Rational
{
public:
    Rational(int n=1,int m=1) {};	 //���캯��
    Rational  R_add(Rational & A);	  //��
    Rational  R_sub(Rational & A);	  //��
    Rational  R_mul(Rational & A);	  //��
    Rational  R_div(Rational & A);	  //��
    void print();         //�Լ������ʽ��ʾ��ע��Լ��
    void simple();
    Rational  Set(int x,int y);		  //Լ��
private:
    int m;            //��ĸ
    int n;             //����
};
void Rational::simple( )
{
    int t;
    int t1=m;
    int t2=n;
    while(t2!=0)
    {
        t=t1%t2;
        t1=t2;
        t2=t;
    }//������Լ��Ϊ t1
    m=m/t1;
    n=n/t1;
}
Rational Rational::R_add(Rational & A)
{
    int t1,t2,t3,t4;
    t1=A.m;
    t2=m;
    t3=A.n;
    t4=n;
    m=t1*t2;
    n=t1*t4+t3*t2;

}
Rational Rational::R_sub(Rational & A)
{
    int t1,t2,t3,t4;
    t1=A.m;
    t2=m;
    t3=A.n;
    t4=n;
    m= t1*t2;
    n= t1*t4-t3*t2;
}
Rational Rational::R_mul(Rational & A)
{
    int t1,t2,t3,t4;
    t1 = A.m;
    t2 = m;
    t3 = A.n;
    t4 = n;
    m = t1*t2;
    n = t3*t4;
}
Rational Rational::R_div(Rational & A)
{
    int t1,t2,t3,t4;
    t1=A.m;
    t2=m;
    t3=A.n;
    t4=n;
    m=t3*t2;
    n=t1*t4;
}
void Rational::print()
{
    simple();
    if(m==n)
        cout <<"1"<<endl;
    else
        cout<<n<<"/"<<m<<endl;
}
Rational Rational::Set(int x,int y)
{
    n=x;
    m=y;
}
int main()
{
    int m1,n1,m2,n2;
    Rational r1,r2;
    cout << "Input two number:\n";
    cin >> n1 >> m1 >> n2 >> m2;
    r1.Set(n1,m1);
    r2.Set(n2,m2);
    cout << "Add:\n";
    r1.R_add(r2);
    r1.print();
    r1.Set(n1,m1);
    r2.Set(n2,m2);
    cout << "Decrease:\n";
    r1.R_sub(r2);
    r1.print();
    r1.Set(n1,m1);
    r2.Set(n2,m2);
    cout << "Multiply:\n";
    r1.R_mul(r2);
    r1.print();
    r1.Set(n1,m1);
    r2.Set(n2,m2);
    cout << "Divide:\n";
    r1.R_div(r2);
    r1.print();
    return 0;
}
