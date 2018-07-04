#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void Sort(int a[],int n)   //n为需处理数据个数
{
    int j;
    for(j=1;j<n;j++)
    {
        int key=a[j];       //key 为需插入的元素
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}
int cheak(int a[],int n,int target) //target 为查找的数，n为数组大小
{
    int low=0; //下限
    int high=n;  //上限
    int middle;   //中间数
    while(low<high)
    {
        middle=(low+high)/2;
        if(target==a[middle])
            return middle;
        if(target<a[middle])
            high=middle;
        if(target>a[middle])
            low=middle;
    }
    return -1;           //找不到则返回-1
}
int main()
{
    int i;
    int iarr[10];
    srand(time(0));
    for(i=0;i<9;i++)
        iarr[i]=rand()%100+1;
    iarr[9]=9;         //只生成9个随机数，第十个数我们自己给出，便于下面的二分查找。
    cout<<"The original array is:\n";
    for(i=0;i<10;i++)
        cout<<iarr[i]<<"   ";
    cout<<endl;
    Sort(iarr,10);
    cout<<"After sorting:\n";
    for(i=0;i<10;i++)
        cout<<iarr[i]<<"   ";
    cout<<endl<<"9 locating "<<cheak(iarr,10,9)+1;  //下标加一为9所在的位置
    return 0;
}
