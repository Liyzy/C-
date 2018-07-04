#include <iostream>

class Carlo
{
private:
    int number;
    double Pprice,Pweight;
    static double Tprice,Tweight;
public :
    Carlo(int number=0,double Pp=0.0,double Pw=0.0,double Tp=0.0,double Tw=0.0);
    ~Carlo() {};
    void sell(Carlo c);
    void buy(Carlo c);
    double getPp()
    {
        return Pprice;
    }
    double getPw()
    {
        return Pweight;
    }
    int getnum()
    {
        return number;
    }
    void disp();
};
double Carlo::Tprice=0.0;
double Carlo::Tweight=0.0;
Carlo::Carlo(int number,double Pp,double Pw,double Tp,double Tw)
{
    this->number=number;
    this->Pprice=Pp;
    this->Pweight=Pw;
    this->Tprice=Tp;
    this->Tweight=Tw;
}
void Carlo::buy(Carlo c)
{
    this->Tprice+=c.getPp()*c.getnum();
    this->Tweight+=c.getPw()*c.getnum();
}
void Carlo::sell(Carlo c)
{
    this->Tprice-=c.getPp()*c.getnum();
    this->Tweight-=c.getPw()*c.getnum();
}
void Carlo::disp()
{
    std::cout<<"Total price is "<<Carlo::Tprice<<std::endl;
    if(Carlo::Tweight>=0)
        std::cout<<"Total weight is "<<Carlo::Tweight<<std::endl;
    else
        std::cout<<"Total weight is Error!";
    }
int main()
{
    Carlo c(0,0.0,0.0,0.0,0.0);
    Carlo c1(9,10.0,25.0);
    Carlo c2(5,13.0,17.5);
    c.disp();
    c.buy(c1);
    c.sell(c2);
    c.disp();
    return 0;
}
