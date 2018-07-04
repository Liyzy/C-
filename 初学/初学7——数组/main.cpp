
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    //cin只读取一个单词
    char name[20];
    char dessert[20];
    cout << "Enter your name:" << endl;
    cin>>name;
    cout<<"Enter your favorite dessert:\n";
    cin>>dessert;
    cout <<"I have some delicious "<<dessert<<" for you, "<<name<<".";

    //数字与字符串混合输入
    cout<<"\nWhat year was your house built?\n";
    int year;
    cin>>year;
    cin.get();
    cout<<"your address:";
    char address[80];
    cin.getline(address,80);
    cout<<"\nAddress:"<<address<<endl;

    //字符类
    string str1="I love ";
    string str2="lihui";
    string str3;
    str3=str1+str2;
    str1+=str2;
    cout<<str3<<endl<<str1<<endl;
    cout<<"str1 contain "<<str1.size()<<" letters."<<endl;//字符串长度统计方法

    string str4;
    getline(cin,str4);
    cout<<endl<<str4<<endl;

    //cout<<endl<<R"+*("(lihui'j'),she whispered.")+*"<<endl;C++11支持。


    return 0;
}
