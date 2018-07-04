/*
Class Rational
{
   long  numerator ;  // 分子
   long  denominator ; // 分母
........
};
1）重载算术运算符“＋”、“-”、“*”、“/”，使之能够适用于有理数的四则运算。
2）重载比较运算符“>”、“ <=” 和“==”，使之能够比较两个有理数。
3）重载运算符“<<”，使其能以规范的方式输出分数，如1/2，-1/3，分母不能为0。
*/

#include <iostream>
using namespace std;
class Rational
{
private:
    long  numerator ;  // 分子
    long  denominator ; // 分母
public:
    Rational() {}
    Rational(long numerator,long denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }
    Rational operator+(const Rational &R);
    Rational operator-(const Rational &R);
    Rational operator*(const Rational &R);
    Rational operator/(const Rational &R);
    bool operator>(const Rational &R);
    bool operator<=(const Rational &R);
    bool operator==(const Rational &R);
    Rational simple();
    friend ostream& operator<<(ostream& out,Rational& R);
};
Rational Rational::simple()
{
    int t1,t2,t;
    Rational tempR;
    if(denominator>numerator)
    {
        t1=denominator;
        t2=numerator;
        while(t2!=0)
        {
            t=t1%t2;
            t1=t2;
            t2=t;
        }
        tempR.denominator=denominator/t1;
        tempR.numerator=numerator/t1;
        return tempR;
    }
    if(denominator==numerator)
    {
        tempR.denominator=1;
        tempR.numerator=1;
    }
    return tempR;
    if(denominator<numerator)
    {
        t2=denominator;
        t1=numerator;
        while(t2!=0)
        {
            t=t1%t2;
            t1=t2;
            t2=t;
        }
        tempR.denominator=denominator/t1;
        tempR.numerator=numerator/t1;
        return tempR;
    }
}
Rational Rational::operator+(const Rational &R)
{
    Rational tempR;
    if(denominator==R.denominator)
    {
        tempR.denominator=denominator;
        tempR.numerator=numerator+R.numerator;
    }
    else
    {
        tempR.denominator=denominator*R.denominator;
        tempR.numerator=numerator*R.denominator+R.numerator*denominator;
    }
    tempR=tempR.simple();
    return tempR;
}
Rational Rational::operator*(const Rational &R)
{
    Rational tempR;
    tempR.denominator=denominator*R.denominator;
    tempR.numerator=numerator*R.numerator;
    tempR=tempR.simple();
    return tempR;
}
Rational Rational::operator-(const Rational &R)
{
    Rational tempR;
    if(denominator==R.denominator)
    {
        tempR.denominator=denominator;
        tempR.numerator=numerator-R.numerator;
    }
    else
    {
        tempR.denominator=denominator*R.denominator;
        tempR.numerator=numerator*R.denominator-R.numerator*denominator;
    }
    tempR=tempR.simple();
    return tempR;
}
Rational Rational::operator/(const Rational &R)
{
    Rational tempR;
    tempR.denominator=denominator*R.numerator;
    tempR.numerator=numerator*R.denominator;
    tempR=tempR.simple();
    return tempR;
}
bool Rational::operator>(const Rational &R)
{
    if(denominator==R.denominator)
    {
        if(numerator>R.numerator)return 1;
        else return 0;
    }
    else
    {
        if(numerator*R.denominator>R.numerator*denominator)return 1;
        else return 0;
    }
}
bool Rational::operator<=(const Rational &R)
{
    if(denominator==R.denominator)
    {
        if(numerator<=R.numerator)return 1;
        else return 0;
    }
    else
    {
        if(numerator*R.denominator<=R.numerator*denominator)return 1;
        else return 0;
    }
}
bool Rational::operator==(const Rational &R)
{
    if(denominator==R.denominator)
    {
        if(numerator==R.numerator)return 1;
        else return 0;
    }
    else
    {
        if(numerator*R.denominator==R.numerator*denominator)return 1;
        else return 0;
    }
}
ostream& operator<<(ostream&out,Rational&R)
{
    if(R.numerator==0)
        out<<0;
    else if(R.numerator==R.denominator)out<<1;
    else
    {
        out<<R.numerator<<'/'<<R.denominator;
    }
    return out;
}
int main()
{
    std::cout << "numerator  denominator\n";
    long numerator1,denominator1,numerator2,denominator2;
    std::cin>>numerator1>>denominator1>>numerator2>>denominator2;
    Rational R1(numerator1,denominator1),R2(numerator2,denominator2);
    Rational R;
    R=R1*R2;
    cout<<R<<endl;
    cout<<(R1==R2);
    return 0;
}
