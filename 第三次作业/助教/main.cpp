#include <iostream>
#include<cstring>
using namespace std;
class teacher
{
private:
    string name;
public :
    teacher(string name)
    {
        this->name=name;
    };
    ~teacher()
    {
        cout<<"bye!";
    }
};
class assist
{
private:
    string name;
    teacher* teacher;
public:
    assist(string name,teacher* teacher)
    {
        this->name=name;
        this->teacher=teacher;
    };
    ~ assist()
    {
        cout<<"bye!";
    }
};
class student
{
private:
    string name;
    assist* assist;
public:
    student(string name,assist* assist)
    {
        this->name=name;
        this->assist=assist;
    };
    ~student()
    {
        cout<<"bye!";
    }
};
int main()
{
    return 0;
}
