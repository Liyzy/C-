#include <iostream>

using namespace std;

class Counter
{
private :
    double number;
public :
    Counter(){number=0;}
    double Add()
    {
        number+=1;
        return number;
    }
    double decrease()
    {
        number-=1;
        return number;
    }
    void disp()
    {
        std::cout<<number<<endl;
    }
};
int main()
{
    Counter c1;
    c1.disp();
    c1.Add();
    c1.disp();
    c1.decrease();
    c1.disp();
    return 0;
}
