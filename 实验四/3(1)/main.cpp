/*设计一个学生类和教师类，学生数据有编号、姓名、班级和成绩；教师数据有编号、姓名、职称和部门；
要求：运用继承的思想实现相关功能：对学生和教师的数据进行输入和显示，类中包括各种构造函数 ，思考如何在派生类的构造函数中初始化基类的成员。
（需要先设计二者的共同基类Person）
*/
#include <iostream>

using namespace std;
class person
{
protected:
    int id;
public:
    person()
    {
        cout<<"Person class constructing...\n";
        int p_id;
        cout<<"input the id:\n";
        cin>>p_id;
        id=p_id;
    }
    ~person()
    {
        cout<<"Person class destructing...\n";
    }
};
class student:public person
{
    int id;
    char* name;
    int Class;
    int score;
public:
    student():person()
    {
        cout<<"student class constructing...\n";
        int s_id;
        char* s_name=new char[20];
        int s_Class;
        int s_score;
        cout<<"input the name,Class,number and score:\n";
        cin>>s_name;
        cin>>s_Class>>s_id>>s_score;
        this->id=s_id;
        this->name=s_name;
        this->Class=s_Class;
        this->score=s_score;
    }
    ~student()
    {
        cout<<"student class destructing...\n";
    }
    void disp();
};
void student::disp()
{
    cout<<"id:"<<person::id<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"number:"<<student::id<<endl;
    cout<<"class:"<<Class<<endl;
    cout<<"score:"<<score<<endl;
}
class teacher:public person
{
    int id;
    char* name;
    char* title;
    char* bumen;
public:
    teacher():person()
    {
        cout<<"teacher class constructing...\n";
        int t_id;
        char* t_name=new char[20];
        char* t_title=new char[30];
        char* t_bumen=new char[30];
        cout<<"input the name,title,number and bumen:\n";
        cin>>t_name>>t_title>>t_id>>t_bumen;
        this->id=t_id;
        this->name=t_name;
        this->title=t_title;
        this->bumen=t_bumen;
    }
    ~teacher()
    {
        cout<<"teacher class destructing...\n";
    }
    void disp();
};
void teacher::disp()
{
    cout<<"id:"<<person::id<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"number:"<<teacher::id<<endl;
    cout<<"title:"<<title<<endl;
    cout<<"bumen:"<<bumen<<endl;
}
int main()
{
    student s;
    s.disp();
    teacher t;
    t.disp();
    return 0;
}
