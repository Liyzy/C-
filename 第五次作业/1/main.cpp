/*编写构造函数，析构函数及其它函数，实现动态分配内存，释放内存和数据输入输出等功能。并进行调试。*/

#include <iostream>
using namespace std;
class Myarray
{
    int *alist;
    int length;
public:
    Myarray( int leng=0,int* a=NULL)
    {
        length=leng;
        alist=new int[length];
    };
    ~Myarray();
    void input();
    void display();
};
void Myarray::input()
{
    int i;
    for(i=0; i<length; i++)
        cin>>*(alist+i);
}
void Myarray::display()
{
    int i;
    for(i=0; i<length; i++)
        cout<<*(alist+i)<< ' ';
}
Myarray::~Myarray()
{
    delete [] alist;
    cout<<endl<<"Bye!" ;
}
int main()
{
    int leng;
    cout<<"Input the length: ";
    cin>>leng;
    Myarray m(leng);
    m.input();
    m.display();
    return 0;
}
