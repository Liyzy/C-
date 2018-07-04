#include <iostream>
#include<string>

using namespace std;

struct people
{
  string name;
  string phone;
};
int main()
{
    people group[3]=
    {
        {
            "lihui","2469660964"
        },
        {
            "liwei","2282455971"
        },
        {
            "liyang","233459867"
        }
    };
    cout << "Lihui's phone is " <<group[0].phone<< endl;
    cout<<"The second one is "<<group[1].name<<endl;
    cout<<group[2].name+group[2].phone<<endl;
    return 0;
}
