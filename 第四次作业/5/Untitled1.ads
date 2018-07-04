//实现下图中的Shape层次结构。每个TwoDimensionalShape类应包括成员函数getArea,
//以计算二维图形的面积。每个ThreeDimensionalShape类包含成员函数getArea和getVolume,
//分别计算三维图形的表面积和体积。编写一个程序，使用层次结构中每个具体类的对象的Shape向量指针。
//程序要打印出向量元素所指的对象。同样，再将所有形状存入向量的循环中，
//要能判断每个图形到底属于TwoDimensionalShape还是属于ThreeDimenionalShape。
//如果某个图形是TwoDimensionalShape就显示其面积，如果某个图形是ThreeDimenionalShape,
//则显示其面积和体积。
#include <iostream>
using namespace std;
const double PI = 3.1415926;

class Shape
{
    public :
        virtual void show()=0;
        virtual double get_area()=0;
        virtual double get_volume()=0;
};
class Twods : public Shape
{
    public :
        virtual double get_area()=0;
        void show(){
            cout << " is TwoDimensionalShape\n";
        }
};
class Threeds : public Shape
{
    public :
        virtual double get_area()=0;
        virtual double get_volume()=0;
        void show(){
            cout << "is ThreeDimensionalShape\n";
        }
};

class Circle : public Twods
{
    private :
        double radius;
    public :
        double get_area(){
            return radius*radius*PI;
        }
        Circle(double radius=0.0){
            this->radius = radius;
        }
        virtual ~Circle(){}
};
class Triangle : public Twods
{
    private :
        double hem;     //底边
        double high;       //高
    public :
        double get_area(){
            return hem*high*0.5;
        }
        Triangle(double hem=0.0,double high=0.0){
            this->hem = hem;
            this->high = high;
        }
};
class Square : public Twods
{
    private :
        double side;
    public :
        double get_area(){
            return side*side;
        }
        Square(double side=0.0){
            this->side = side;
        }
};
class Sphere : public Threeds
{
    private :
        double radius;
    public :
        double get_area(){
            return 4*PI*radius*radius;
        }
        double get_volume(){
            return 4/3*PI*radius*radius*radius;
        }
        Sphere(double radius=0.0){
            this->radius = radius;
        }
};
class Cube : public Threeds
{
    private :
        double side;
    public :
        double get_area(){
            return 6*side*side;
        }
        double get_volume(){
            return side*side*side;
        }
        Cube(double side=0.0){
            this->side = side;
        }
};
int main()
{
    cout << "zhizhag";
    Circle ci(4.0);
    Triangle tr(2,3);
    Square sq(4);
    Sphere sp(3);
    Cube cu(4);
    Shape *group[5];
    Twods *to;
    Threeds *th;
    group[0] = &ci;
    group[1] = &tr;
    group[2] = &sq;
    group[3] = &sp;
    group[4] = &cu;
    int i;
    for(i=0;i<5;i++)
    {
            group[i]->show();
            cout << group[i]->get_area();
    }
    return 0;
}
