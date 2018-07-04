/*
1.��main�����г�ʼ��������ά���ݣ�����A��һ��3*4�ľ��󣬾���B��һ��4*2�ľ���

2. ͨ�������������A*B=C�ľ���˷�������main�����������������
*/
#include <iostream>
#include <iomanip>
using namespace std;

void arrayMultiply(int (*pA)[4], int (*pB)[2], int (*pC)[2])
{
    int i,j,k;
    for(k=0; k<3; k++)
        for(j=0; j<2; j++)
            for(i=0; i<4; i++)
                *(*(pC+k)+j)+=*(*(pA+k)+i) * *(*(pB+i)+j);
}
void printArray(int (*pC)[2])
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
            cout<<setw(8)<<*(*(pC+i)+j);
        cout<<endl;
    }
}
int main()
{
    int i,j;
    int A[3][4],B[4][2],C[3][2]= {0};
    cout<<"Input two array:\n";
    for(i=0; i<3; i++)
        for(j=0; j<4; j++)
            cin>>A[i][j];
    for(i=0; i<4; i++)
        for(j=0; j<2; j++)
            cin>>B[i][j];
    arrayMultiply(A,B,C);
    printArray(C);
    return 0;
}
