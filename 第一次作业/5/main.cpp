#include<iostream>
#include<cmath>
#include<ctime>
#include<stdlib.h>

using namespace std;

int  main()
{
    int n, i;
    double rate = 1;
    cout << "Input the number of the students :" << endl;
    cin >> n;
    for (i = 365; i >= 366 - n; i--)
        rate *= (double)i / 365;
    cout << n << "rate is " << rate;
}


