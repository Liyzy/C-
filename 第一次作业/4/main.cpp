#include <iostream>

using namespace std;

int main()
{
    cout << "Input two numbers:" << endl;
    int x,y;
    cin>>x>>y;
    void my_swap(int & p1,int & p2);
    my_swap(x,y);
    cout<<x<<' '<<y;
    return 0;
}
void my_swap(int & p1,int & p2)
{
   int p;
   p=p1;
   p1=p2;
   p2=p;
}
