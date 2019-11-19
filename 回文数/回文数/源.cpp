//判断回文数
#include<iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		//先判断是否小于0，是的话一定不是回文数
		if (x<0)
		{
			return false;
		}
		//回文数反转一定还是回文数
		int inverse = 0;
		int origin = x;
		while (x!=0)
		{
			int rem = x % 10; //取余数
			x /= 10;
			//判断是否越界,如果本身是回文数则必不会越界
			if (inverse>INT_MAX/10 || inverse==INT_MAX/10&&rem>7)
			{
				return false;
			}
			else
			{
				inverse = inverse * 10 + rem;
			}
		}
		if (inverse==origin)
		{
			return true;
		}
		return false;
	}
};

//一种更巧妙的方法，只反转一半
class SolutionA {
public:
	bool isPalindrome(int x) {
		//先判断是否小于0，是的话一定不是回文数
		if (x<0 || (x % 10 == 0 && x != 0))//因为如果一个数的结尾是0，那么它一定不是回文数,除非它本身就为0
		{
			return false;
		}
		//回文数反转一定还是回文数
		int inverse = 0;
		while (1)
		{
			int rem = x % 10; //取余数
			x /= 10;
			//判断是否越界,如果本身是回文数则必不会越界
			//因为只反转一半，故不再需要判断越界
			/*if (inverse>INT_MAX / 10 || inverse == INT_MAX / 10 && rem>7)
			{
			return false;
			}
			else
			{
			inverse = inverse * 10 + rem;
			}*/
			inverse = inverse * 10 + rem;
			//我们将原始数字除以 10，然后给反转后的数字乘上 10，所以，当原始数字小于反转后的数字时，就意味着我们已经处理了一半位数的数字。
			if (inverse == x)//偶数个数字组成的话这种情况下相等为回文数
			{
				return true;
			}
			if (inverse>x)
			{
				//判断是否可能是奇数个数字的情况
				if (inverse / 10 == x) //因为inverse是反转的，除10相当于去除中间一位
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
};
int main()
{
	int x = 121;
	Solution a;
	a.isPalindrome(x);
	cin.get();
}