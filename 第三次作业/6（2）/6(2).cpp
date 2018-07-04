#include <iostream>

class Intset;
class floatset
{
private:
    float num[3];
public:
    friend void settofloat(Intset &I_set,floatset &m_set);
    floatset ( float x,float y, float z)
    {
        num[0]=x;
        num[1]=y;
        num[2]=z;
    }
    void print()
    {
        std::cout <<num[0]<<' '<<num[1]<<' '<<num[2]<<std::endl;
    }
};
class Intset
{
private:
    int num[3];
public:
    friend void settofloat(Intset &I_set,floatset &m_set);
    Intset ( int x,int y, int z)
    {
        num[0]=x;
        num[1]=y;
        num[2]=z;
    }
    void print( )
    {
        std::cout <<num[0]<<' '<<num[1]<<' '<<num[2]<<std::endl;
    }
};
void settofloat(Intset &I_set,floatset &m_set)
{
    m_set.num[0]=I_set.num[0];
    m_set.num[1]=I_set.num[1];
    m_set.num[2]=I_set.num[2];
}
int main()
{
    Intset i1(1,2,3);
    floatset f1(2.7,3.8,9.4);
    i1.print();
    f1.print();
    settofloat(i1,f1);
    i1.print();
    f1.print();
    return 0;
}

