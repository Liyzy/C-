/*
1.在main函数中初始化两个二维数据，矩阵A是一个3*4的矩阵，矩阵B是一个4*2的矩阵。

2. 通过函数调用完成A*B=C的矩阵乘法，并在main函数中输出计算结果。
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
