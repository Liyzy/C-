#include <iostream>
#include <cmath>
class Circle
{
private :
    double x,y;
    double r;
public :
    Circle(double x=0,double y=0,double r=0) {this->x = x; this->y = y; this->r =r;};
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
};
double distance (Circle C1,Circle C2)
{
    double x1,y1,x2,y2;
    x1=C1.getX();
    x2=C2.getX();
    y1=C1.getY();
    y2=C2.getY();
    return sqrt((x1-x2)*(x1-x2)+(y2-y1)*(y2-y1));
}
int main()
{
    double x1,y1,r1,x2,y2,r2,dis;
    std::cout << "Input the (x,y) and r:\n";
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    Circle C1(x1,y1,r1);
    Circle C2(x2,y2,r2);
    dis = distance(C1,C2);
    if(dis>(r1+r2))
        std::cout << "xiangli\n" ;
    if(dis<(r1+r2))
            std::cout << "xiangjiao\n" ;
    if(dis==(r1+r2))
            std::cout << "xiangqie\n";
    return 0;
}
