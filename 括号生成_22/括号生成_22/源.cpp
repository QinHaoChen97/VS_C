/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {//注意n是生成括号的对数，不是生成括号的个数，所以生成长度应该是2*n
		vector<string> all;
		if (n<=0)
		{
			return all;
		}
		int length = 2 * n;//生成括号的长度
		generateall(length, 0, "", all);
		return all;
	}
	void generateall(int &length,int n, string sin, vector<string> &all)//暴力法生成所有方案，再判断是否符合规则
	{
		if (n==length)//判断生成的长度是否到达终点
		{
			if (istrue(sin))//如果生成的字符串正确，则推入数组
			{
				all.push_back(sin);
			}
			return;
		}
		else//生成的长度不对	
		{
			generateall(length, n + 1, sin + "(",all);
			generateall(length, n + 1, sin + ")",all);
		}
		return;
	}
	bool istrue(string sin)//判断生成的字符串是否符合规则
	{
		int n = 0;
		for (auto ch:sin)
		{
			if (ch=='(')
			{
				n++;
			}
			else
			{
				n--;
			}
			if (n<0)//说明生成的括号对不正确
			{
				return false;
			}
		}
		if (n==0)//生成正确的括号对
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	Solution a;
	a.generateParenthesis(3);
	cin.get();
}