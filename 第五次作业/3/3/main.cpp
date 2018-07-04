/*����һ����revarray�̳��� myarray, ʹ���鰴�����ţ�����������е��ԡ�*/
#include <iostream>
class myarray
{
protected:
    int* arr;
    int leng;
public:
    myarray(int leng=0);
    ~myarray();
    void input();
};
myarray::myarray(int length)
{
    std::cout<<"Input the number:";
    std::cin>>length;
    leng=length;
    arr=new int[length];
    std::cout<<"base constructing...\n";
}
myarray::~myarray()
{
    delete []arr;
    std::cout<<"base destructing...\n";
}
void myarray::input()
{
    int i;
    for(i=0;i<leng;i++)
        std::cin>>arr[i];
}
class revarray:public myarray
{
    int* revarr;
public:
    revarray(int l=0,int* r=NULL):myarray(l)
    {
        revarr=new int[leng];
        std::cout<<"derived constructing...\n";
    }
    ~revarray()
    {
        delete []revarr;
        std::cout<<"\nderived destructing...\n";
    }
    void rev();
    void disp();
};
void revarray::rev()
{
    revarr=new int[leng];
    int i,j;
    for(i=leng-1,j=0;i>=0;i--,j++)
        revarr[j]=arr[i];
}
void revarray::disp()
{
    int i;
    for(i=0;i<leng;i++)
        std::cout<<revarr[i]<<' ';
}
int main()
{
    revarray r;
    r.input();
    r.rev();
    r.disp();
    return 0;
}
