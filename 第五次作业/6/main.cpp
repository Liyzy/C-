/*6. 编写一个程序，实现字符串操作：
	一个简单串类string，包含输入字符串、返回字符串长度及内容等功能；
	另有一个具有编辑功能的串类edit_string，它继承string类，在其中设置一个光标，使其能支持在光标处的插入、替换和删除等编辑功能。*/

#include <iostream>
#include<cstring>
using namespace std;
class String
{
protected:
    char* arr;
public:
    String(char* c=NULL);
    ~String(){delete [] arr;cout<<"String class destructing...\n";}
    void input();
    void getlength();
    void disp();
};
String::String(char* c)
{
    if(c==NULL)
        arr=new char[100];
    else
        arr=c;
        cout<<"String class constructing...\n";
}
void String::input()
{
    cin>>arr;
}
void String::disp()
{
    cout<<arr<<endl;
}
void String::getlength()
{
    cout<<strlen(arr)<<endl;
}
class edit_String:public String
{
    int GB;
public:
    edit_String(char* c=NULL,int gb=0):String(c)
    {
        cout<<"INput the location of the GB: ";
        cin>>gb;
        GB=gb;
        cout<<"edit_String class constructing...\n";
    }
    ~edit_String(){delete []arr;cout<<"edit_String class destructing...\n";}
    void Insert();
    void Delete();
    void Replace();
    void disp(){cout<<arr<<endl;}
};
void edit_String::Insert()
{
    cout <<"Input the string you want to insert: ";
    char temp[100]={0},in[100]={0};
    cin>>in;
    unsigned int i,j;
    for(i=GB,j=0;i<strlen(arr);i++,j++)
        temp[j]=arr[i];
    for(i=GB;i<GB+strlen(in);i++)
        arr[i]=in[i-GB];
    for(i=GB+strlen(in),j=0;i<strlen(in)+strlen(arr);i++,j++)
        arr[i]=temp[j];
}
void edit_String::Replace()
{
    cout <<"Input the string you want to replace: ";
    char re[100]={0};
    cin>>re;
    unsigned int i;
    for(i=GB;i<GB+strlen(re);i++)
        arr[i]=re[i-GB];
}
void edit_String::Delete()
{
    cout <<"Input the string you want to delete: ";
    char temp[100]={0},de[100]={0};
    cin>>de;
    unsigned int i,j,leng=strlen(arr);
    for(i=GB+strlen(de),j=0;i<strlen(arr);i++,j++)
        temp[j]=arr[i];
    for(i=GB;i<strlen(arr);i++)
        arr[i]={0};
    for(i=GB,j=0;i<leng-strlen(de)+GB;i++,j++)
        arr[i]=temp[j];
}
int main()
{
    edit_String es;
    es.input();
    es.getlength();
    es.Insert();
    es.disp();
    es.Replace();
    es.disp();
    es.Delete();
    es.disp();
}
