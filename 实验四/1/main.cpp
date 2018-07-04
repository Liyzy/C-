/*�����м򵥴���myString�Ļ����������ַ�����String1�����а��������ַ����������ַ������ȼ����ݵȹ��ܣ�����ʵ���ַ���������Ƚϣ����ÿ⺯������
���һ�����б༭���ܵĴ���String2������String1������������
��Ա�����ܹ������ַ���ָ��λ�ô�ʵ�����²����������ַ������滻��ɾ��ĳ���ַ��� ���ܲ����Ӵ���*/

#include <iostream>
#include<cstring>
using namespace std;
class String
{
protected:
    char* arr;
public:
    String(char* c=NULL);
    ~String()
    {
        delete [] arr;
        cout<<"String class destructing...\n";
    }
    void input();
    void getlength();
    void disp();
    void m_strcat(String & s);
    void m_strcmp(String & s);
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
    cout<<"length :"<<strlen(arr)<<endl;
}
void String::m_strcat(String & s)
{
    int i,j;
    char p1[100]= {0};
    for(i=0; *(arr+i)!='\0'; i++)
    {
        j=i+1;
        p1[i]=*(arr+i);
    }
    for(i=0; *(s.arr+i)!='\0'; i++,j++)
        p1[j]=*(s.arr+i);
    cout<<"lianjie:"<<p1<<endl;
}
void String::m_strcmp(String & s)
{
    int i;
    char *pp1,*pp2;
    pp1=arr;
    pp2=s.arr;
    for(i=0; *arr++!='\0'&&*s.arr++!='\0'; i++)
    {
        if(*arr-*s.arr>0)
        {
            cout<<"da:"<<pp2<<endl;
            break;
        }
        if(*arr-*s.arr<0)
        {
            cout<<"da:"<<pp1<<endl;
            break;
        }
        if(*arr-*s.arr==0)
            continue;
    }
}
class String2:public String
{
    int GB;
public:
    String2(char* c=NULL,int gb=0):String(c)
    {
        cout<<"INput the location of the GB: ";
        cin>>gb;
        GB=gb;
        cout<<"String2 class constructing...\n";
    }
    ~String2()
    {
        delete []arr;
        cout<<"String2 class destructing...\n";
    }
    void Insert();
    void Delete();
    void Replace();
    void disp()
    {
        cout<<arr<<endl;
    }
};
void String2::Insert()
{
    cout <<"Input the string you want to insert: ";
    char temp[100]= {0},in[100]= {0};
    cin>>in;
    unsigned int i,j;
    for(i=GB,j=0; i<strlen(arr); i++,j++)
        temp[j]=arr[i];
    for(i=GB; i<GB+strlen(in); i++)
        arr[i]=in[i-GB];
    for(i=GB+strlen(in),j=0; i<strlen(in)+strlen(arr); i++,j++)
        arr[i]=temp[j];
}
void String2::Replace()
{
    cout <<"Input the string you want to replace: ";
    char re[100]= {0};
    cin>>re;
    unsigned int i;
    for(i=GB; i<GB+strlen(re); i++)
        arr[i]=re[i-GB];
}
void String2::Delete()
{
    cout <<"Input the string you want to delete: ";
    char temp[100]= {0},de[100]= {0};
    cin>>de;
    unsigned int i,j,leng=strlen(arr);
    for(i=GB+strlen(de),j=0; i<strlen(arr); i++,j++)
        temp[j]=arr[i];
    for(i=GB; i<strlen(arr); i++)
        arr[i]='0';
    for(i=GB,j=0; i<leng-strlen(de)+GB; i++,j++)
        arr[i]=temp[j];
}
int main()
{
    String2 es,ss;
    es.input();
    es.getlength();
    /*ss.input();              �ַ�����������Ƚ�
    ss.getlength();
    es.m_strcat(ss);
    es.m_strcmp(ss);*/

    /*es.Insert();             ���룬ɾ�����滻
    es.disp();
    es.Replace();
    es.disp();
    es.Delete();
    es.disp();*/
}
