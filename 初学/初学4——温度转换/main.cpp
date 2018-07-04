#include <iostream>

using namespace std;

double change(double Cdegree)
{
    double Fdegree;
    Fdegree=1.8*Cdegree+32.0;
    return Fdegree;
}
int main()
{
    double Cdegree,Fdegree;
    cout << "Please enter a Celsius value:" ;
    cin>>Cdegree;
    Fdegree=change(Cdegree);
    cout<<Cdegree<<" degrees Celsius is "<<Fdegree<<" degrees Fahrenheit.";
    return 0;
}
