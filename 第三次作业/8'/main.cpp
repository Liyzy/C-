#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int number[100];
struct Node
{
    int num;
    Node *next;
};

class INT
{
private:
    Node *d;
    Node *head;
    static int counter;
public:
    friend void up(INT& I1);
    INT()
    {
        this->d=NULL;
        this->head=NULL;
    }
    ~INT()
    {
        cout<<"bye!"<<endl;
    }
    void creat(int a);
    void build();
    void disp();
};

int INT::counter=0;

void INT::creat(int a)
{
 if(head==NULL)
	{
        head=new Node;
        head->num=a;
        head->next=NULL;
        counter++;
    }
    else
	{
        d=head;
        while(d->next!=NULL)
			d=d->next;
        Node* k=new Node;
        k->num=a;
        d->next=k;
        k->next=NULL;
        counter++;
    }
}
void INT::build()
{
    int i;
    srand(time(0));
    for(int i=0; i<100; i++)
        number[i]=rand()%200+10;
    for(i=0; i<100; i++)
    {
        if(i==0) this->creat(number[i]);
        else
        {
            if(number[i]>number[i-1])
                this->creat(number[i]);
        }
    }
}
void up(INT & I1)
{
    int sum=0;
    Node* temp=I1.head->next;
    if(I1.head->next==0)
        cout<<"Error!";
    while(temp!=NULL)
    {
        Node* q=temp->next;
        sum+=temp->num;
        I1.head->next=q;
        delete temp;
        temp=q;
    }
    cout<<"sum is "<<sum<<endl;
}
void INT::disp()
{
    Node* p;
    p=head->next;
    while(p)
    {
        cout<<p->num<<"\t";
        p=p->next;
    }
    cout<<endl<<"counter is "<<counter;
}
int main()
{
    INT I1;
    I1.build();
    I1.disp();
    cout<<"\n";
    up(I1);
    return 0;
}

