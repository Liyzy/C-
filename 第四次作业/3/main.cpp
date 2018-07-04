/*定义一个集合类Set，最多存放100个不重复的整数，实现集合的如下操作：
1）增加某个整型元素时，保证集合中没有重复元素；删除指定的元素，查找该元素在集合中则从集合中删除该元素；
2）重载运算符“+”，实现两个集合对象的合并操作，重载运算符“*”，求两个集合对象的交集；例如Set s, s1, s2; s = s1+s2; s = s1* s2;
3）重载赋值运算符=和复合赋值运算符-= ， 实现两个集合对象的赋值操作与差集操作。例如Set s1，s2；s1 = s2;   s1-=s2; 集合S1中去掉S2中存在的元素。*/

#include<iostream>
using namespace std;
class Set
{
private:
	int arr[100];
public:
	Set() { for (int i = 0; i < 100;i++)arr[i]=0; }
	void print() { for (int i = 0; i < 100; i++)if(arr[i]!=0)cout << arr[i] << endl; }
	Set add(int a);
	Set del(int a);
	Set operator+(Set& s);
	Set operator*(Set& s);
	Set& operator=(const Set& s);
	Set& operator-=(const Set& s);
};
Set Set::add(int a)
{
	int i, flag;
	for (flag=0,i = 0; i < 100; i++)
	{
		if(a==this->arr[i]&&flag==0)
		{
			cout << "Again！" << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		for (i = 0; i < 100; i++)
			if (this->arr[i] == 0)
			{
				this->arr[i] = a;
				break;
			}
	}
	return *this;
}
Set Set::del(int a)
{
	int i,flag;
	for (flag=0,i = 0; i < 100; i++)
	{
		if (this->arr[i] == a)
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
	{
		cout << "no" << endl;
		return *this;
	}
	else
	{
		for (i; i < 99; i++)
		{
			this->arr[i] = this->arr[i + 1];
			if (this->arr[i] == 0)
			{
				this->arr[i + 1] = 0;
				break;
			}
		}
		return *this;
	}
}
Set Set::operator+( Set& s)
{
	int i, j;
	Set temp = *this;
	for (i = 0; i < 100; i++)
		if (temp.arr[i] == 0)
			break;
	for (j = 0; j < 100; j++)
		if (s.arr[j] == 0)
			break;
	if (i + j >= 100)
	{
		cout << "wrong!" << endl;
		return temp;
	}
	for (j = 0, i; i < 100, j < 100; i++, j++)
	{
		if (s.arr[j] != 0)
			temp.arr[i] = s.arr[j];
		else
			break;
	}
	return temp;
}
Set Set::operator*(Set& s)
{
	int i, j,k=0,flag;
	Set temp = *this;
	Set temp2;
	for (flag=0,i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (s.arr[j] == temp.arr[i]&&temp.arr[i]!=0&&s.arr[j]!=0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			temp2.arr[k] = s.arr[i], k++;
	}
	cout<<1<<' '<<2;
	return temp2;
}
Set& Set::operator-=(const Set& s)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (s.arr[i] != 0)
			this->del(s.arr[i]);
	}
	return *this;
}
Set& Set::operator=(const Set& s)
{
	for (int i = 0; i < 100; i++)
		this->arr[i] = s.arr[i];
	return *this;
}
int main()
{
    Set set1, set2, set3;
    set1.add(1);
     set1.add(2);
    set1.add(3);
    cout<<"set1=";
     set1.print();
    set2.add(1);
     set2.add(2);
    set1 -= set2;
    cout<<"chajiwei:";
    set1.print();
    cout<<"jiaojiwei:";
    set3=set1*set2;
    return 0;
}

