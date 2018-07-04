/*（1）用函数模板方式设计一个函数模板sort<T>，采用直接插入排序方式对数据进行排序，并对整数序列和字符序列进行排序。*/

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
