#include <iostream>

using namespace std;

int main()
{
    int i,sum=0,my_max,my_min;
    int* p=new int[9];
    cout<<"Input some numbers :";
    for(i=0;i<9;i++)
        cin>>*(p+i);
    for(i=0;i<9;i++)
        sum+=*(p+i);
    my_max=*p;my_min=*p;
    for(i=0;i<9;i++)
    {
        if(*(p+i)>my_max)
            my_max=*(p+i);
        if(*(p+i)<my_min)
            my_min=*(p+i);
    }
    cout<<"Sum is "<<sum<<endl
        <<"Max is "<<my_max<<endl
        <<"Min is "<<my_min;
    delete [] p;
    return 0;
}
