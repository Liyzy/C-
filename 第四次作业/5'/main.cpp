#include<iostream>
#include<cstring>
using namespace std;
class String
{
private:
public:
    char *s;
    int length;
public:
    String (char * p=NULL);
    String (int a);
    String(const String &a)//复制构造函数
    {
        s=new char[a.length+1];
        length=a.length;
        strcpy(s,a.s);
    }
    ~ String();
    String operator +(const String &a);
    String operator =(const String &a);
    bool operator <(const String &a);
    friend ostream& operator<< (ostream& out,const String &a)
    {
        for(int i=0; i<a.length; ++i)
        {
            out<<a.s[i];//out
        }
        return out;//return out
    }
    friend istream& operator>> (istream& in,const String &a)
    {
        for(int i=0 ; i<a.length; ++i)
        {
            in>>a.s[i];//in>>a.s[i]
        }
        return cin;
    }

};
String ::String (int a)
{
    length=a;
    s=new char[length+1];
}
String:: String(char *p)
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
String::~String()
{

    delete[]s;
    length=0;
}
String String::operator +(const String &a)//应该写成+=吧，左操作数都改了
{
    int j=0;
    int i;
    char *p=new char[length+a.length+1];
    for( i=0; i<length; ++i)
    {
        p[j]=s[i];
        ++j;
    }
    for(i=0; i<a.length; ++i)
    {
        p[j]=a.s[i];
        ++j;
    }
    p[j]=0;
    delete[]s;
    s=p;
    length+=a.length;
    return *this;
}

bool String:: operator <(const String &a)
{
    if (length<a.length)
        return true;
    else
        return false;
}
String String::operator =(const String &a)
{
    delete[]s;
    s=new char[a.length+1];
    length=a.length;
    strcpy(s,a.s);
    return *this;
}

int main()
{
    String s1("asdfg"),s3("abc"),s2("aaa");
    s2=s1+s3;
    cout<<s2<<endl;
    return 0;
}
