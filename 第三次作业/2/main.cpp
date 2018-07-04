#include <iostream>

class  plural
{
private:
    double a,b;
public:
      plural(double a=0.0,double b=0.0);
      friend void add(plural p1, plural p2);
      friend void subtraction(plural p1, plural p2);
      friend void divide(plural p1, plural p2);
      friend void multiply(plural p1, plural p2);
};
plural::plural(double a,double b)
{
    this->a=a;
    this->b=b;
}
void add(plural p1,plural p2)
{
    std::cout<<"add is "<<p1.a+p2.a<<"+"<<p1.b+p2.b<<"i\n";
}
void subtraction(plural p1, plural p2)
{
    std::cout<<"subtraction is "<<p1.a-p2.a<<"+"<<p1.b-p2.b<<"i\n";
}
void divide(plural p1, plural p2)
{
    std::cout<<"divide is "<<(p1.a*p2.a+p1.b*p2.b)/(p2.a*p2.a+p2.b*p2.b)<<(p1.b*p2.a-p1.a*p2.b)/(p2.a*p2.a+p2.b*p2.b)<<"i\n";
}
void multiply(plural p1, plural p2)
{
    std::cout<<"multiply is "<<p1.a*p2.a-p1.b*p2.b<<"+"<<p1.a*p2.b+p1.b*p2.a<<"i\n";
}
int main()
{
    plural p1(3.0,4.0),p2(2.0,7.0);
    add(p1,p2);
    subtraction(p1,p2);
    divide(p1,p2);
    multiply(p1,p2);
    return 0;
}
