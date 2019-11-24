//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
//
//示例 1 :
//
//输入: "(()"
//	输出 : 2
//	解释 : 最长有效括号子串为 "()"
//	示例 2 :
//
//	输入 : ")()())"
//	输出 : 4
//	解释 : 最长有效括号子串为 "()()"
//
#include<iostream>
using namespace std;
/*
https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/
动态规划的方法
*/
class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length();
		if (n==0)
		{
			return 0;
		}
		int *pd = new int[n]; //要用动态分配，数组存储当前位置连续子字符串的个数
		for (int i=0;i<n;i++) //初始化
		{
			pd[i] = 0;
		}
		//每两位每两位的判断
		for (int i = 1; i < n; i++) //首位无需判断
		{
			if (s[i]=='(')
			{
				continue;//若是(那么该位肯定要为0
			}
			else if (s[i]==')' && s[i-1]=='(')
			{
				if (i>2)
				{
					pd[i] = pd[i - 2] + 2;
				}
				else//在第二位的情况
				{
					pd[i] = 2;
				}
			}
			else// "))"的情况，因为只存在两种字符
			{
				if (i-pd[i-1]>0 && s[i-pd[i-1]-1]=='(')  //注意这里要做放越界的处理
				{
					if (i-pd[i-1]>1)
					{
						pd[i] = pd[i - 1] + pd[i - pd[i - 1] - 2] + 2;
						//这时候要注意原先被认为可能是不连续的i-pd[i-1]-1也被纳入的连续的部分了，所以若是该位置前面有连续的有效
						//括号部分，则应该纳入整个连续有效括号的长度中，故要加上pd[i-pd[i-1]-2]
					    //注意这里也要防数组访问越界
					}
					else
					{
						pd[i] = pd[i - 1] + 2;
					}
					 
				}
			}
		}
		int maxlen = pd[0];
		for (int i = 1; i < n; i++)
		{
			if (pd[i]>maxlen)
			{
				maxlen = pd[i];
			}
		}
		return maxlen;
	}
};
int main()
{
	string s = "(()())";
	Solution a;
	a.longestValidParentheses(s);
	cin.get();
}