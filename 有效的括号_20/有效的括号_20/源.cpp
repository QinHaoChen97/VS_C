/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
//利用栈
class Solution {
public:
	bool isValid(string s) {
		int n = s.length();
		stack<char> sta;
		for (int i = 0; i < n; i++)
		{
			if (sta.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				sta.push(s[i]);
			}
			else
			{
				if (s[i]==')')
				{
					if (sta.top()=='(')
					{
						sta.pop();
					}
					else
					{
						return false;
					}
				}
				else if(s[i]==']')
				{
					if (sta.top() == '[')
					{
						sta.pop();
					}
					else
					{
						return false;
					}
				}
				else if (s[i]=='}')
				{
					if (sta.top() == '{')
					{
						sta.pop();
					}
					else
					{
						return false;
					}
				}
			}
		}
		if (sta.empty())
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
	string s = "()";
	Solution a;
	a.isValid(s);
	cin.get();
}