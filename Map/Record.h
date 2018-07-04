#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
#include <cstring>

using namespace std;

class Record
{
public:
    Record(int linkID, bool roadNameFlag, int bruch, int dispClass, char* roadName);
    ~Record(){}
    Record(){}
    Record(Record & R);
    void show();

    unsigned int linkID;

private:
    bool roadNameFlag;
    unsigned int bruch;
    unsigned int dispClass;
    string roadName;
};

#endif // RECORD_H_INCLUDED
