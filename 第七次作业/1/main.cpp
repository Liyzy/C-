/*��1���ú���ģ�巽ʽ���һ������ģ��sort<T>������ֱ�Ӳ�������ʽ�����ݽ������򣬲����������к��ַ����н�������*/

#include <iostream>

using namespace std;

template < class T>
void Sort(T s[], int n)
{
    int i,j;
    for(i=2;i<=n;i++)
       {
           s[0]=s[i];
           j=i-1;
           while(s[0]<s[j])
           {
               s[j+1]=s[j];
               j--;
           }
           s[j+1]=s[0];
       }
}

int main()
{
    int i;
    int iarr[6];
    char carr[6];
    cout<<"Input 5 number.\n";
    for(i=1;i<6;i++)
        cin>>iarr[i];
    Sort(iarr,5);
    for( i=1;i<6;i++)
        cout<<iarr[i]<<' ';
    cout<<endl;
     cout<<"Input 5 char.\n";
    for(i=1;i<6;i++)
        cin>>carr[i];
    Sort(carr,5);
    for( i=1;i<6;i++)
        cout<<carr[i]<<' ';
    return 0;
}
