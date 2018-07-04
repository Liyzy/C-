#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int* YangHuiData(int n); //n是杨辉三角形的行数
void YangHuiShow(int *pData,int n);//在屏幕上打印杨辉三角形

int main()
{
    int n;
    cout<<"请输入杨辉三角形的行数"<<endl;
    cin>>n;
    int *pData = YangHuiData(n);    //计算杨辉三角并保存到二维数组
    YangHuiShow(pData,n);   //在屏幕上打印等腰三角形的杨辉三角
    return 0;
}

int* YangHuiData(int n)   //n是杨辉三角形的行数
{
    int *a = new int[n*n];
//完成杨辉三角形的计算，没有显示的位置填0
    int i,j;
    for(i=0; i<n; i++)
        a[i*n+0]=1;
    for(i=1; i<n; i++)
        a[i*n+i]=1;
    for(i=1; i<n-1; i++)
        for(j=0; j<i; j++)
            a[(i+1)*n+(j+1)]=a[i*n+j]+a[i*n+(j+1)];
    return a;
}

void YangHuiShow(int *a,int n)
{
//根据数据a指向的二维数组在屏幕上打印
//杨辉三角形，每行前面填充合适的空格
//以显示成等腰三角形，左右对称
    int i,j;
    cout<<"========\\ yanghuisanjiao //========\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
            cout<<"   ";
        for(j=0; j<i+1; j++)
            cout<<setw(6)<<a[i*n+j];
        cout<<endl;
    }
}

