#include<iostream>
#include<vector>
using namespace std;
//�����룬�����򵥣�����Ҫ֪����ʽ
//���ױ��빫ʽ G(i) = i ^ (i / 2);
//�� n = 3:
//G(0) = 000,
//G(1) = 1 ^ 0 = 001 ^ 000 = 001
//G(2) = 2 ^ 1 = 010 ^ 001 = 011
//G(3) = 3 ^ 1 = 011 ^ 001 = 010
//G(4) = 4 ^ 2 = 100 ^ 010 = 110
//G(5) = 5 ^ 2 = 101 ^ 010 = 111
//G(6) = 6 ^ 3 = 110 ^ 011 = 101
//G(7) = 7 ^ 3 = 111 ^ 011 = 100
//��������������������������������
//��Ȩ����������ΪCSDN������Zolewit����ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/zolewit/article/details/90715308
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> gray;
		for (int i = 0; i < (1<<n); i++)	//C++�洢��ʱ��ʵ����2���ƣ�������ʵ�����ǳ�2��1<<n=1*2��n�η���nλ�����빲��2^n-1����Ԫ
		{
			gray.push_back(i ^ (i / 2));	//���ݸ�����Ĺ�ʽ��ע��^��c++�е����
		}
		return gray;
	}
};
int main()
{
	int a = 0b1111;
}