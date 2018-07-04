#include <iostream>
#include <cstring>
#include "Record.h"

using namespace std;

Record::Record(int linkID, bool roadNameFlag, int bruch, int dispClass, char* roadName)
{
    this->linkID = linkID;
    this->roadNameFlag = roadNameFlag;
    this->bruch = bruch;
    this->dispClass = dispClass;
    this->roadName = roadName;
}

Record::Record(Record & R)
{
    R.linkID = linkID;
    R.roadNameFlag = roadNameFlag;
    R.bruch = bruch;
    R.dispClass = dispClass;
    strcpy(roadName, R.roadName);
}

void Record::show()
{
    cout<< linkID<< " "<<roadNameFlag<< " "<< bruch<< " "<<dispClass<< " "<<roadName<<endl;
}

