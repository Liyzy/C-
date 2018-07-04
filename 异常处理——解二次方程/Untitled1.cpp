#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double a=0; double b=0; double c=0;
	try{ cout<<"请输入一元二次方程的系数a,b,c"<<endl;
          cin>>a>>b>>c;
	      double delta = b*b - 4*a*c;
        if (delta<0) throw delta;
	    if (delta==0) cout<<"方程有唯一根 "<<(-b/2/a)<<endl;
		else { cout<<"方程有两个根： "<<endl;
	                cout<<((-b+sqrt(delta))/2/a)<<"  ";
	                cout<<((-b-sqrt(delta))/2/a)<<endl;  }
	}catch(double  d){
     cout<<"delta="<<d<<"，根据此系数方程无实根。"<<endl;
	} }
