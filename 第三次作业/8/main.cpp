#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

struct node
{
    int num;
    node* next;
};
class Int
{
private:
    node* head;
    node* d;
    static int counter;
public:
    Int(){this->d=0;this->head=0;}
    ~Int(){cout<<"bye!"<<endl;}
    void creat(int a);
    void display();
};
int Int::counter=0;
void Int::creat(int a)
{
   if(head==NULL)
	{
        head=new node;
        head->num=a;
        head->next=NULL;
        counter++;		//¼ÆÊýÆ÷
    }
    else
	{
        d=head;
        while(d->next!=NULL)
			d=d->next;
        node* k=new node;
        k->num=a;
        d->next=k;
        k->next=NULL;
        counter++;
    }
}
int msrand()
{
    int i,a,b;
    srand(time(0));
   for(i=0;i<100;i++)
   {
       a=rand()%200+10;
       b=rand()%200+10;
       while(a>b)
       {
           b=rand()%200+10;
       }
       a=b;
   }
   return b;
}
void Int::display()
{
    node* p;
    p=head->next;
    while(p)
    {
        cout<<p->num<<' ';
        p=p->next;
    }
}
int main()
{
    Int I1;
    I1.creat(msrand());
    I1.display();
    return 0;
}
