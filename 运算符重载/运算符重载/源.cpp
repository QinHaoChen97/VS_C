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
istream & operator >> (istream &in, oper& c1)//�������ý����ô�ֵ�Ĳ������أ���ô��Ӧ����������������Ҫ����Ϊ���������
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