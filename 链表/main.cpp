#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node* next;
};
void Add(Node* h)
{
   int x;
   cout<<"Input a new number:\n";
   cin>>x;
   while(x!=-1)
    {
        Node *t=new Node;
        t->x=x;
        t->next=h->next;
        h->next=t;
        cin>>x;
    }
}
void Delete(Node* h)
{
    int x;
    int det;
    Node* p,* pre;
    p=h->next;
    pre=h;
    cout<<"Please input the number you want to delete :"<<endl;
    cin>>det;
    while (p)
    {
        if(p->x==det)
        {
            pre->next=p->next;
            delete p;
            p=pre->next;
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
    void display(Node* h);
    display(h);
}
void display(Node* h)
{
    Node* p;
    p=h->next;
    while(p)
    {
        cout<<p->x<<' ';
        p=p->next;
    }
}
void modify(Node* h)
{
    int mod,new_num;
    Node* p;
    p=h->next;
    cout<<"The number you want to modify:\n";
    cin>>mod;
    while(p)
    {
       if(p->x==mod)
       {
           cout<<"Input the new number:";
           cin>>new_num;
           p->x=new_num;
       }
       else
           p=p->next;
    }
}
void Find(Node* h)
{
    Node* p;
    p=h->next;
    int Fin;
    cout<<"The number you want to find:";
    cin>>Fin;
    while(p)
    {
        if(p->x==Fin)
            cout<<p->x;
        p=p->next;
    }
}
int main()
{
    int x;
    Node* h=new Node;
    h->next=0;
    cout << "Please input numbers:" << endl;
    cin>>x;
    while(x!=-1)
    {
        Node *t=new Node;
        t->x=x;
        t->next=h->next;
        h->next=t;
        cin>>x;
    }
    Delete(h);
    return 0;
}
