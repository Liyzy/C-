#include <iostream>

using namespace std;

int main()
{
    int a=9;
    int* p=&a;
    cout<<"a="<<p<<endl;
    cout<<"a="<<&a<<endl;

    int* pi=new int;
    *pi=2;
    cout <<"*pi="<<*pi<<endl;
    cout <<"address of "<<*pi<<" is "<<pi<<endl;
    delete pi;
    cout <<*pi<<"  "<<pi;

    char flower[10]="Rose";
    cout<<endl<<flower<<"s are red."<<endl;


    return 0;
}
