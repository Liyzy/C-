#include<iostream>
#include<cmath>
#include<ctime>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,i,j,k,flag;
    double rate,num=0;
    int a[365];
    srand(time(0));
    cout<< "Input the number of the students :"<<endl;
    cin>>n;
    for (k=0;k<10000;k++)
        for (flag=0,i=0; i<n; i++)
        {
            a[i]=rand()%365+1;
            for (j=0; j<i; j++)
                if (a[i] == a[j])
                    flag=1;
            if(i==n-1 && flag != 1)
                num++;
        }
    rate=num/10000;
    cout<<"rate is :"<<rate;
    return 0;
}
