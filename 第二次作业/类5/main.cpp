#include <iostream>

using namespace std;

class Z
{
private :
    int *p;
public:
    Z()
    {
      p=new int[10];
    }
    ~Z()
    {
       delete [] p;
        std::cout <<"bye";
    }
    void Input();
    void Output()
    {
        int i;
        for(i=0; i<10; i++)
            std::cout <<*(p+i)<<" ";
    }
};
void Z::Input()
{
    int i;
    for(i=0;i<10;i++)
    std::cin>>*(p+i);
}
int main()
{
    Z z;
    z.Input();
    z.Output();
    return 0;
}
