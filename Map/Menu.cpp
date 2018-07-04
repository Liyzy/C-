#include <iostream>
#include <list>
#include <conio.h>
#include "Record.h"

using namespace std;

void Menu()
{
    cout<< "/******************************电子地图管理系统******************************/\n";
    cout<< "选择服务种类:\n";
    cout<< "1.读取文件\n";
    cout<< "2.排序并输出排序结果\n";
    cout<< "3.检索\n";
    cout<< "4.更新\n";
    cout<< "0.退出\n";
    switch(getch() - 48)
    {
    case 1:
        break;
    case 2:
        Sort(m_record[]);
        break;
    case 3:
        break;
    case 4:
        break;
    case 0:
        return;
    }
}
