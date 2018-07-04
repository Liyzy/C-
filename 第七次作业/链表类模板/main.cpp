#include <iostream>
#include <cstdlib>
using namespace std;

template<class T> // T为结点类型
struct Node       // 结构结点
{     Node* pNext;
        T  data ;
};

template<class T>
class List{
public:
    List(){};
    ~List(){};
    void Add(const T& th);         // 添加结点
    void Remove(const T& th);  // 删除节点
    void PrintList( );     // 遍历链表
protected:
     Node<T>* pFirst;       //链首结点指针
};
template<class T>
void List<T>::Add(const T& th)
{
    Node<T>* a=new Node<T>;
    a->data=th;
    a->pNext=pFirst->pNext;
    pFirst->pNext=a;
}
template<class T>
void List<T>::PrintList()
{
    while(pFirst->pNext!=NULL)
    {
        cout<<pFirst->data<<" ";
        pFirst++;
    }
}
int main()
{
    List<int>lis;
    lis.Add(1);
    lis.Add(2);
    lis.PrintList();
}
