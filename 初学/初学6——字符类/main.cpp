#include <iostream>

using namespace std;

int main()
{
    cout << '$' <<endl;

    cout.put('$');
    cout<<'\a'<<endl;
    cout<<"abcd\"de";

    long code;
    cout<<"Enter your agent code:_______\b\b\b\b\b\b\b";
    cin>>code;

    short inum;
    inum=9;
    cout<<sizeof(int)<<endl<<sizeof inum;

    cout<<endl<<"g\u00E2teau.\n";//\u00E2ÎªISO 10646±ê×¼¡£

    cout<<endl<<int('q');
    return 0;
}
