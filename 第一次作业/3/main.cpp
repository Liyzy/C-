#include <iostream>

using namespace std;

int main()
{
    int i,j,k,counter=0;
    for(i=0; i<=100; i++)
        for(j=0; j<=50; j++)
            for(k=0; k<=20; k++)
                if(i+2*j+5*k==100)
                    counter++;
    cout <<counter<< " ways!" << endl;
    return 0;
}
