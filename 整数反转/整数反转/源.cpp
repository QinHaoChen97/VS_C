#include<iostream>
using namespace std;
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//
//示例 1 :
//
//输入: 123
//	输出 : 321
//	示例 2 :
//
//	输入 : -123
//	输出 : -321
//	示例 3 :
//
//	输入 : 120
//	输出 : 21
//	注意 :
//
//	假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31, 2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

class Solution {
public:
	int reverse(int x) {
		bool positive = true;//用于判断是正还是负
		if (x<0)
		{
			positive = false;
		}
		int temp = 0;//存储翻转的数
		int remain;//存储余数
		while (x!=0)
		{	
			remain = x % 10;	//取出最后一位
			x /= 10;	//去除最后一位
			if (positive)		//正数判断上届
			{
				if (temp>INT_MAX/10 || (temp==INT_MAX/10 && remain>7))
				{
					return 0;
				}
			}
			else //负数判断下界
			{
				if (temp<INT_MIN/10 || (temp==INT_MIN/10 && remain<-8))
				{
					return 0;
				}
			}
			temp = temp * 10 + remain;	//妙处，每次都乘10这样最开始的余数便会被推到最高位，不用去计算这个整数的位数
		}
		return temp;	
	}
};
int main()
{
	int a = 3;
	cout << a /10 << endl;
	cin.get();
}