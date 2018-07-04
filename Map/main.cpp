#include <iostream>
#include "Menu.h"
#include "Record.h"

using namespace std;

int main()
{
    Record m_record[4] =
    {
        Record(1234, 1, 2, 3, "hhh"),
        Record(1239, 1, 2, 3, "xxx"),
        Record(1125, 1, 2, 3, "yyy"),
        Record(1024, 1, 2, 3, "zzz")
    };
    for(int i=0; i < 4; i++)
       m_record[i].show();
    Menu();
    return 0;
}
