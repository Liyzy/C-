#include <iostream>
#include "Record.h"

void Sort(Record R[])
{
    Record temp;
    for(int i=0; i < 3; i++)
        for(int j=0; j < 4-i; j++)
    {
        if(R[j].linkID > R[j+1].linkID)
        {
            temp = R[j+1];
            R[j+1] = R[j];
            R[j] = temp;
        }
    }
}
