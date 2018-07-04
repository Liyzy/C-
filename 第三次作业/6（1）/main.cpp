#include <iostream>

class floatset
{
private:
    float num[3];
public:
    friend class Intset;
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
    void settofloat(floatset &m_set)
    {
        m_set.num[0]=num[0];
        m_set.num[1]=num[1];
        m_set.num[2]=num[2];
    }
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
    int main()
    {
        Intset i1(1,2,3);
        floatset f1(2.7,3.8,9.4);
        i1.print();
        f1.print();
        i1.settofloat(f1);
        i1.print();
        f1.print();
        return 0;
    }
