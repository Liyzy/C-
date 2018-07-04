/*编写一个程序，先设计一个链表List类，再从链表类派生出一个集合类Set类，再集合类中添加一个记录元素个数的数据项。
要求可以实现对集合的插入、删除、查找和显示。*/

#include<iostream>
#include<string>

using namespace std;

class node
{
public:
    node* next;
    node* Front;
    int x;
    friend class List;
};
class List
{
private:
    node* head;
    node* tail;
    node* temp;
public:
    void add(int);
    List();
    ~List();
    void show();
};
class Set :public List
{
private:
    node *head, *tail, *temp;
    int len;
public:
    void add(int);
    void Delete(int);
    node*Find(int);
    void show();
    Set();
    ~Set();
    int getnum();
};
int Set::getnum()
{
    return len;
}
void Set::show()
{
    node *t = head;
    while (t)
    {
        cout << t->x << " ";
        t = t->next;
    }
    cout << endl;
}
Set::Set()
{
    head = tail = temp = NULL;
    len = 0;
    cout<<"Set class constructing...\n";
}
Set::~Set()
{

    while (head)
    {
        node*t = head;
        t = t->next;
        delete head;
        head = t;
    }
    cout<<"Set class destructing...\n";
}
void Set::add(int x)
{
    temp = new node;
    temp->x = x;
    temp->Front = NULL;
    temp->next = NULL;
    if (!head)
    {
        head = tail = temp;
        len = 1;
    }
    else
    {
        node *t = head;
        len++;
        while (t)
        {
            if (x > tail->x)
            {
                tail->next = temp;
                temp->Front = tail;
                tail = temp;
                break;
            }
            if (t != head)
            {
                if (x < t->x)
                {
                    if (x == t->Front->x)
                    {
                        len--;
                        break;
                    }
                    temp->next = t;
                    t->Front->next = temp;
                    t->Front = temp;
                    break;
                }
            }
            else
            {
                if (x < t->x)
                {
                    temp->next = t;
                    t->Front = temp;
                    head = temp;
                    break;
                }
            }
            t = t->next;
        }
    }
}
List::List()
{
    cout<<"List class constructing...\n";
    head = tail = temp = NULL;
}
List::~List()
{
    while (head)
    {
        node*t = head;
        t = t->next;
        delete head;
        head = t;
    }
    cout<<"List class destructing...\n";
}
void List::add(int x)
{
    temp = new node;
    temp->x = x;
    temp->next = NULL;
    if (tail == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void List::show()
{
    node *t = head;
    while (t)
    {
        cout << t->x << " ";
        t = t->next;
    }
    cout << endl;
}
void Set::Delete(int x)
{
    node* t = head;
    bool flag = 0;
    while (t)
    {
        if (t->x == x)
        {
            flag = 1;
            len--;
            if (t == head)
            {
                t = head->next;
                delete head;
                head = t;
                break;
            }
            else
            {
                t->Front->next = t->next;
                delete t;
                break;
            }
        }
        t = t->next;
    }
    if (!flag)
        cout << "Error!" << endl;
}
node* Set::Find(int x)
{
    node*t = head;
    bool flag = false;
    while (t)
    {
        if (t->x == x)
        {
            flag = true;
            return t;
        }
        t = t->next;
    }
    if (!flag)
        cout << "mistake" << endl;
    return NULL;
}
int main()
{
    List lis;
    lis.add(1);
    lis.add(2);
    lis.add(3);
    lis.show();
    Set se;
    for (int i = 0; i < 5; i++)
    {
        se.add(i);
    }
    se.add(3);
    se.show();
    cout << se.getnum() << endl;
    se.Delete(3);
    se.show();
    node *t = se.Find(2);
    cout << t->x << endl;
    cout << se.getnum() << endl;
    return 0;
}
