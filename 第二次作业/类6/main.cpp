#include <iostream>

using namespace std;

class String
{
public:
    String(const char *str = NULL);  //普通构造函数
    String(const String &other);     //拷贝构造函数
    ~ String();                   //析构函数
private:
    char *m_data; // 用于保存字符串
};
String::String(const char *str)
{
    m_data=new char[10];
    str=m_data;
    cout<<"Gouzao\n";
}
String::String(const String &other)
{
    m_data=new char[10];
    cout<<"kaobei\n";
}
String::~String()
{
    cout<<"bye\n";
}
int main()
{
    String Str1;
    String Str2=Str1;
}
