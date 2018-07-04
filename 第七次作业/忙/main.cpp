#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void Sort(int a[],int n)   //nΪ�账�����ݸ���
{
    int j;
    for(j=1;j<n;j++)
    {
        int key=a[j];       //key Ϊ������Ԫ��
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}
int cheak(int a[],int n,int target) //target Ϊ���ҵ�����nΪ�����С
{
    int low=0; //����
    int high=n;  //����
    int middle;   //�м���
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
    return -1;           //�Ҳ����򷵻�-1
}
int main()
{
    int i;
    int iarr[10];
    srand(time(0));
    for(i=0;i<9;i++)
        iarr[i]=rand()%100+1;
    iarr[9]=9;         //ֻ����9�����������ʮ���������Լ���������������Ķ��ֲ��ҡ�
    cout<<"The original array is:\n";
    for(i=0;i<10;i++)
        cout<<iarr[i]<<"   ";
    cout<<endl;
    Sort(iarr,10);
    cout<<"After sorting:\n";
    for(i=0;i<10;i++)
        cout<<iarr[i]<<"   ";
    cout<<endl<<"9 locating "<<cheak(iarr,10,9)+1;  //�±��һΪ9���ڵ�λ��
    return 0;
}
