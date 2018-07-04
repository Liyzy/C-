/*����ַ�����String������String�����s1��s2��s3�����������ʵ�����²�����
    1�����ء�����ʵ���ַ������ӹ��ܣ�ʹ���ʽs1= s2+s3������
    2�����ء�<���ж������ַ����Ĵ�С���� if(s1 < s2) cout<<s1<<��<��<<s2��
3�����ء�<<���롰>>����ʵ���ַ����������������������cin>>s2; cout<<s2<<endl;
4�������������()�������ַ��������з���һ���Ӵ�����s1(2,4)��ʾ���ش��Ӵ�������s[2](s1��3���ַ�)��ʼ���Ӵ�(����s1[2]��s1[3]��s1[4]�����ַ�)��*/

#include <iostream>
#include<cstring>
using namespace std;
class String
{
private:
    char* s;
    int length;
public:
    String(char* p=NULL);
    String(int a);
    String operator+(String& s1);
    bool operator<(String& s1);
    void operator()(int a,int b);
    friend istream& operator>>(istream& in,String& S);
    friend ostream& operator<<(ostream& out,String& S);
};
String::String(char* p)
{
    if(p)
    {
        length=strlen(p);
        s = new char[length+1];
        strcpy(s,p);
    }
    else
        cout<<"unknown"<<endl;
}
String::String(int a)
{
    length=a;
    s=new char[length+1];
}
void String::operator()(int a,int b)
{
    int i;
    for(i=a;i<=b;i++)
     cout<<endl<<s[i];
}
bool String::operator<(String& s1)
{
    if (length<s1.length)
        return true;
    else
        return false;
}
String String::operator+(String& s1)
{
    int j=0;
    int i;
    char *p=new char[length+s1.length+1];
    for( i=0; i<length; ++i)
    {
        p[j]=s[i];
        ++j;
    }
    for(i=0; i<s1.length; ++i)
    {
        p[j]=s1.s[i];
        ++j;
    }
    p[j]=0;
    delete[]s;
    s=p;
    length+=s1.length;
    return *this;
}
istream& operator>>(istream& in,String& S)
{
    int i;
    for( i=0; i<S.length; ++i)
    {
        in>>S.s[i];
    }
    return in;
}
ostream& operator<<(ostream& out,String& S)
{
    int i;
    for( i=0; i<S.length; ++i)
    {
        out<<S.s[i];
    }
    return out;
}
int main()
{
    cout << "Input two string:\n";
    String S(5),S1(2),S2(3);
    cin>>S1;
    cin>>S2;
    if(S1<S2)cout<<endl<<"Compare:"<<S1<<" "<<S2<<endl;
    S=S1+S2;
    cout<<S;
    S(2,4);
    return 0;
}
