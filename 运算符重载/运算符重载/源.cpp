#include<iostream>
using namespace std;
class oper {
public:
	friend istream & operator >> (istream &in,  oper& c1);
	int real, image;
	oper(int a,int b)
	{
		real = a;
		image = b;
	}
};	
istream & operator >> (istream &in, oper& c1)//这里是用将引用传值的参数返回，那么相应的整个函数的类型要声明为该类的引用
{		
	in >> c1.real;
	return in;
}
int main()
{
	oper a(1,2);
	cin >> a>>a;
	cout << a.real;
	cin >> a;
}