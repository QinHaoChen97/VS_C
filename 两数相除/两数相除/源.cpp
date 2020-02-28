/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
//本质是把被除数分解为2的n次方的和，如10/3;10刚好大于3*(2^1+2^0)
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend==0 || dividend<divisor)
		{
			return 0;
		}
		else if(dividend==INT_MIN && divisor==-1)//唯一会产生结果溢出的情况
 		{
			return INT_MIN;
		}
		else if(dividend==divisor)
		{
			return 1;
		}
		//先判断符号位,并将运算都转移到负数，这样因为INT_MIN绝对值大于INT_MAX
		bool pos = true;//符号位
		if (dividend>0 && divisor<0)
		{
			dividend = -dividend;
			pos = false;
		}
		else if(dividend<0 && divisor >0)
		{
			divisor = -divisor;
			pos = false;
		}
		else if (dividend > 0 && divisor > 0)
		{
			dividend = -dividend;
			divisor = -divisor;
		}
		int result = 0;
		int segresult = 1;
		int nowdivisor = divisor;
		int mod = dividend;//存储每次的差值（余数）
		while (1)
		{
			if (mod==divisor)
			{
				result = result + 1;
				if (!pos)//结果是负数
				{
					return -result;
				}
				return result;
			}
			else if (divisor<mod)
			{
				if (!pos)
				{
					return -result;
				}
				return result;
			}
			//求小于mod的最大2的n次方
			bool overflow = false;
			while (nowdivisor>mod)//注意越界
			{
				nowdivisor = nowdivisor << 1;//乘二
				segresult = segresult << 1;
				if (nowdivisor<INT_MIN/2)//这样的话下一次乘二会越界，所以要跳出循环了
				{
					if (nowdivisor<mod)
					{
						break;
					}
					else//否则要做相应的处理，与之后的处理相抵消
					{
						overflow = true;
						segresult = segresult << 1;
						break;
					}
				}
			}
			//已经得到小于mod的最大的2的n+1次方，故要退回到大于mod的最小的2的n次方（注意这里讨论的前提都为负数）
			segresult = segresult >> 1;
			result += segresult;
			if (overflow)
			{
				mod = mod - nowdivisor;
			}
			else
			{
				mod = mod - (nowdivisor >> 1);
			}
			nowdivisor = divisor;
			segresult = 1;
		}
	}
};
int main()
{
	int a = INT_MAX;
	int b = -3;
	Solution A;
	int c = A.divide(a, b);
}