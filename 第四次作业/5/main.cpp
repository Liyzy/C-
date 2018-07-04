/*设计字符串类String，若有String类对象s1、s2和s3，重载运算符实现如下操作：
    1）重载“＋”实现字符串连接功能，使表达式s1= s2+s3成立；
    2）重载“<”判断两个字符串的大小，如 if(s1 < s2) cout<<s1<<”<”<<s2；
3）重载“<<”与“>>”，实现字符串的输入与输出操作，如cin>>s2; cout<<s2<<endl;
4）重载运算符“()”，从字符串对象中返回一个子串。如s1(2,4)表示返回从子串，即从s[2](s1第3个字符)开始的子串(包括s1[2]、s1[3]和s1[4]三个字符)。*/

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
