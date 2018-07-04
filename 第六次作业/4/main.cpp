/*ʵ����ͼ�е�Shape��νṹ��ÿ��TwoDimensionalShape��Ӧ������Ա����getArea,�Լ����άͼ�ε������
ÿ��ThreeDimensionalShape�������Ա����getArea��getVolume,�ֱ������άͼ�εı�����������
��дһ������ʹ�ò�νṹ��ÿ��������Ķ����Shape����ָ�롣����Ҫ��ӡ������Ԫ����ָ�Ķ���
ͬ�����ٽ�������״����������ѭ���У�Ҫ���ж�ÿ��ͼ�ε�������TwoDimensionalShape��������ThreeDimenionalShape��
���ĳ��ͼ����TwoDimensionalShape����ʾ����������ĳ��ͼ����ThreeDimenionalShape,����ʾ������������*/

#include<iostream>
#include<cmath>
#define pi 3.14
using namespace std;
class shape
{
public:
    virtual double getarea() = 0;
    virtual void show() {};
    virtual void showname() {};
};
class twoshape:public shape
{
public:
    void show()
    {
        cout <<"This is a twoshape.\nArea is "<< getarea() << endl;
    }
};
class threeshape:public shape
{
public:
    virtual double getvolum() = 0;
    void show()
    {
        cout <<"This is a threeshape.\nArea is "<< getarea() << endl <<"Volume is "<< getvolum() << endl;
    }
};
class square :public twoshape
{
private:
    double size;
public:
    square(double sizes) :size(sizes) {}
    double getarea()
    {
        return size*size;
    }
    void showname()
    {
        cout << "square" << endl;
    }
};
class triangle :public twoshape
{
private:
    double a, b, c;
public:
    triangle(double d, double e, double f) :a(d), b(e), c(f) {}
    double getarea()
    {
        double s = (a + b + c) / 2;
        return sqrt(s*(s - a)*(s - b)*(s - c));
    }
    void showname()
    {
        cout << "truangle" << endl;
    }
};

class circle :public twoshape
{
private:
    double r;
public:
    circle(double rr) :r(rr) {}
    double getarea()
    {
        return pi*r*r;
    }
    void showname()
    {
        cout << "circle" << endl;
    }
};
class sphere :public threeshape
{
private:
    double r;
public:
    sphere(double rr) :r(rr) {}
    double getarea()
    {
        return pi * 4 * r*r;
    }
    double getvolum()
    {
        return pi * 4 / 3 * r*r*r;
    }
    void showname()
    {
        cout << "sphere" << endl;
    }
};
class cube :public threeshape
{
private:
    double a, b, c;
public:
    cube(double d, double e, double f) :a(d), b(e), c(f) {}
    double getarea()
    {
        return 2 * (a*b + b*c + c*a);
    }
    double getvolum()
    {
        return a*b*c;
    }
    void showname()
    {
        cout << "cube" << endl;
    }
};
int main()
{
    shape*arr[5];
    square squ(2);
    triangle tri(3, 4, 5);
    circle ci(2);
    sphere sp(2);
    cube cub(3, 4, 5);
    arr[0] = &squ;
    arr[1] = &tri;
    arr[2] = &ci;
    arr[3] = &sp;
    arr[4] = &cub;
    for (int i = 0; i < 5; i++)
    {
        arr[i]->showname();
        arr[i]->show();
    }
}
