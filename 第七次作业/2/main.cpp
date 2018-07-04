/*用类模板方式设计一个栈类stack<T>，其中有两个私有数据成员：s[]（存放栈元素）和top（栈顶元素下标），
以及3个公有成员函数：push（元素入栈）、pop（元素出栈）和stackempty（判断栈是否为空），并建立一个整数栈和一个字符栈。
   const int Max=2
   template < class T>
   class stack
   {
      T s[Max];
      int top;
   public:
      void push(T x);
      void pop(T & x);  //弹出结果放在x变量中
      int stackempty();  //栈空返回1，否则返回0
   };
*/
#include <iostream>
using namespace std;
const int Max=2;
template < class T>
class Stack
{
    T s[Max];
    int top;
public:
    Stack()
    {
        top=0;
    }
    void push(T x);
    void pop(T & x);  //弹出结果放在x变量中
    int stackempty();  //栈空返回1，否则返回0
    void show();
};
template<class T>
void Stack<T>::push(T x)
{
    if(top<=Max)
    {
        s[top]=x;
        top++;
    }
    if(top>Max)
        cout<<"Error!\n";
}
template<class T>
void Stack<T>::pop(T & x)
{
    if(stackempty())
        cout<<"Empty!\n";
    else
    {
        x=s[top-1];
        cout<<endl<<x<<endl;
        top--;
    }
}
template<class T>
int Stack<T>::stackempty()
{
    if(top==0)
        return 1;
    else
        return 0;
}
template<class T>
void Stack<T>::show()
{
    int i;
    for(i=0; i<top; i++)
        cout<<s[i]<<"  ";
}
int main()
{
    int i;
    char c;
    Stack<int>s1;
    Stack<char>s2;
    s1.push(1);
    s1.push(2);
    s1.show();
    s1.pop(i);
    s2.push('a');
    s2.push('b');
    s2.show();
    s2.pop(c);
    if(!s1.stackempty())
        cout<<"Not Empty.";
    return 0;
}
