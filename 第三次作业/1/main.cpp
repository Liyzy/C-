#include <iostream>
class Myclass
{
public:
    Myclass (int a,int b)
    {
        x=a;
        y=b;
    }
    void copy(Myclass & m);
    void print( )
    {
        using namespace std;
        cout<<"x="<<x<<endl;
        cout<<"y="<<y<<endl;
    }
private:
    int x,y;
};
void Myclass::copy(Myclass & m)
{
    Myclass temp(this->x,this->y);
    this->x=m.x;
    this->y=m.y;
    m.x=temp.x;
    m.y=temp.y;
}
int main()
{
    Myclass my(10,20),t(30,40);
    my.print( );
    my.copy(t);
    my.print( );
    t.print();
}
