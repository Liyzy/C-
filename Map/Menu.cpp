#include <iostream>
#include <list>
#include <conio.h>
#include "Record.h"

using namespace std;

void Menu()
{
    cout<< "/******************************���ӵ�ͼ����ϵͳ******************************/\n";
    cout<< "ѡ���������:\n";
    cout<< "1.��ȡ�ļ�\n";
    cout<< "2.�������������\n";
    cout<< "3.����\n";
    cout<< "4.����\n";
    cout<< "0.�˳�\n";
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
