#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int* YangHuiData(int n); //n����������ε�����
void YangHuiShow(int *pData,int n);//����Ļ�ϴ�ӡ���������

int main()
{
    int n;
    cout<<"��������������ε�����"<<endl;
    cin>>n;
    int *pData = YangHuiData(n);    //����������ǲ����浽��ά����
    YangHuiShow(pData,n);   //����Ļ�ϴ�ӡ���������ε��������
    return 0;
}

int* YangHuiData(int n)   //n����������ε�����
{
    int *a = new int[n*n];
//�����������εļ��㣬û����ʾ��λ����0
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
//��������aָ��Ķ�ά��������Ļ�ϴ�ӡ
//��������Σ�ÿ��ǰ�������ʵĿո�
//����ʾ�ɵ��������Σ����ҶԳ�
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

