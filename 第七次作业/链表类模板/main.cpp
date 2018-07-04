#include <iostream>
#include <cstdlib>
using namespace std;

template<class T> // TΪ�������
struct Node       // �ṹ���
{     Node* pNext;
        T  data ;
};

template<class T>
class List{
public:
    List(){};
    ~List(){};
    void Add(const T& th);         // ��ӽ��
    void Remove(const T& th);  // ɾ���ڵ�
    void PrintList( );     // ��������
protected:
     Node<T>* pFirst;       //���׽��ָ��
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
