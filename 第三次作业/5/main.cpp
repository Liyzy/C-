#include <iostream>

class node
{
private:
    double member;
    static int counter;
public:
    node(double member=0.0);
    ~node();
    void disp();
    static int getcounter(){std::cout<<counter;return counter;}
};
int node::counter=0;
node::node(double member)
{
    this->member=member;
    counter++;
}
node::~node()
{
    counter--;
}
void node::disp()
{
    std::cout <<"member = "<<member<<std::endl;
    std::cout <<"counter = "<<node::counter<<std::endl;
}
int main()
{
    node n1(19.7);
    node n2(13.5);
    node n3(27.4);
    n1.disp();
    n2.disp();
    n3.disp();
    n1.~node();
    n2.~node();
    n3.~node();
    n1.disp();
    n2.disp();
    n3.disp();
    n1.getcounter();
    return 0;
}
