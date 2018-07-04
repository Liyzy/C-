#include <iostream>

using namespace std;

struct Record
{
    int   linkID;
    bool  roadNameFlag;
    int   bruch;
    int   dispClass;
    char* roadName;
};

int main()
{
    Record m_record[4] =
    {
        {1234,1,2,3,"hhh"},
        {1298,1,2,3,"zzz"},
        {1122,1,2,3,"xxx"},
        {1024,1,2,3,"ttt"}
    };
//    void Q_sort(Record record[], Record start, Record end);
//    Q_sort(m_record, m_record[0], m_record[3]);
    void find(Record record[]);
    find(m_record);
    return 0;
}

void show(Record record[])
{
    for (int i=0; i < 4; i++)
        cout<< record[i].linkID << " "<<record[i].roadNameFlag<<" "<<record[i].bruch<<" "<<record[i].dispClass<<" "<<record[i].roadName<<endl;
}

// 冒泡排序
void M_sort(Record record[])
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4-i; j++)
            if(record[j].linkID > record[j+1].linkID)
            {
                Record temp;
                temp = record[j];
                record[j] = record[j+1];
                record[j+1] = temp;
            }
    show(record);
}

//快速排序
void Q_sort(Record record[], Record start, Record end)
{
    int i, j;
    record[i] = start;
    record[j] = end;
    Record key = record[0];
    //第一趟快排
    while(i < j)
    {
        while(i < j && key.linkID < record[j].linkID)
            j--;
        if(i < j)
        {
            record[i] = record[j];
            i++;
        }
        while(i < j && record[i].linkID <= key.linkID)
            i++;
        if(i < j)
        {
            record[j] = record[i];
            j--;
        }
    }
    //递归调用Q_sort函数
    record[i] = key;
    if(start.linkID < record[i].linkID)
        Q_sort(record, start, record[j-1]);
    if(record[i].linkID < end.linkID)
        Q_sort(record, record[j+1], end);
    show(record);
}

//遍历查找
void find(Record record[])
{
    int i, f_linkID;
    cout<< "intput the linkID you want to find:\n";
    for(i=0; i < 4; i++)
    {
        if(record[i].linkID == f_linkID)
        {
            cout<< record[i].linkID << " "<<record[i].roadNameFlag<<" "<<record[i].bruch<<" "<<record[i].dispClass<<" "<<record[i].roadName<<endl;
            continue;
        }
    }
}


