/*2．定义一个类averarray继承自myarray，在类中求数组的平均值，并输出。进行调试。*/

#include <iostream>

using namespace std;

class myarray {
protected:
    int *num;
    int amount;
public:
    myarray(int amount = 0, int *num = NULL) {
        cout << "Input the amount: " << endl;
        cin >> amount;
        cout << "Construction!\n";
        this->amount = amount;
        num = new int[amount];
    }

    ~myarray() {
        delete[]num;
        cout << "Bye!\n";
    }

    void input();

    void disp();

};

void myarray::input() {
    int i;
    num = new int[amount];
    for (i = 0; i < amount; i++)
        cin >> *(num + i);
}

void myarray::disp() {
    int i;
    for (i = 0; i < amount; i++)
        cout << *(num + i) << " ";
}

class averarray : public myarray {
    double average;
public:
    averarray(int amount = 0, int *num = NULL, double average = 0.0) : myarray(amount, num) {
        this->average = average;
        cout << "p constructing.\n";
    }

    ~averarray() { cout <<endl << "p bye.\n"; }

    void getaver();
};

void averarray::getaver() {
    int sum = 0;
    int i;
    for (i = 0; i < amount; i++)
        sum += *(num + i);
    cout<<endl<<"average is "<<(double)sum / amount;
}

int main() {
    averarray a;
    a.input();
    a.disp();
    a.getaver();
    return 0;
}
