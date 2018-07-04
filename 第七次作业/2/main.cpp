/*����ģ�巽ʽ���һ��ջ��stack<T>������������˽�����ݳ�Ա��s[]�����ջԪ�أ���top��ջ��Ԫ���±꣩��
�Լ�3�����г�Ա������push��Ԫ����ջ����pop��Ԫ�س�ջ����stackempty���ж�ջ�Ƿ�Ϊ�գ���������һ������ջ��һ���ַ�ջ��
   const int Max=2
   template < class T>
   class stack
   {
      T s[Max];
      int top;
   public:
      void push(T x);
      void pop(T & x);  //�����������x������
      int stackempty();  //ջ�շ���1�����򷵻�0
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
    void pop(T & x);  //�����������x������
    int stackempty();  //ջ�շ���1�����򷵻�0
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
