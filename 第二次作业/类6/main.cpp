#include <iostream>

using namespace std;

class String
{
public:
    String(const char *str = NULL);  //��ͨ���캯��
    String(const String &other);     //�������캯��
    ~ String();                   //��������
private:
    char *m_data; // ���ڱ����ַ���
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
