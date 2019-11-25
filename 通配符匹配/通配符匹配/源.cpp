/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<string>
using namespace std;
//方法一，递归，逐步缩减s,p的长度
//超时
class Solution {
public:
	bool isMatch(string s, string p) {
		int s_size = s.length(), p_size = p.length();
		if (p_size==0 && s_size==0) //说明匹配
		{
			return true;
		}
		if (p_size==0 && s_size!=0)
		{
			return false;
		}
		if (p_size>0) //p的长度不为0
		{
			if (p[0]=='?')
			{
				if (s_size>0)
				{
					return isMatch(s.substr(1), p.substr(1));
				}
				else//s_size==0
				{
					return false;
				}
			}
			else if(p[0]=='*')
			{
				if (p_size>1 && p[0] == p[1]) //即**的情况，可等同于一个*
				{
					return isMatch(s, p.substr(1));
				}
				if (s_size>0)
				{
					return isMatch(s.substr(1), p) || isMatch(s, p.substr(1));//包含所有p[0]=‘*’可能进行的操作
				}
				else//s_size==0
				{
					return isMatch(s, p.substr(1));
				}
			}
			else if (s_size>0 && p[0]==s[0])
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else//p[0]==字母且p[0]!=s[0]
			{
				return false;
			}	
		}
		return false; //实际上不会运行到这里,用于防止Leetcode运行报无返回值
	}
};

//动态规划
class SolutionA {
public:
	bool isMatch(string s, string p) {
		//构造动态数组m+1行，n+1列,pd[m+1-1][n+1-1] bool数组， pd[i][j]表示 s的前i个字符和p的前i个字符是否匹配
		int m = s.length(), n = p.length();
		bool **pd = new bool*[m + 1];
		for (int i = 0; i < m+1; i++)
		{
			pd[i] = new bool[n + 1];
		}
		//初始化数组
		//pd[0][0]代表两个空数组，肯定为true
		pd[0][0] = true;
		//pd[i][0]肯定为false
		for (int i = 1; i < m+1; i++)
		{
			pd[i][0] = false;
		}
		//pd[0][j]只有在p[0][j]都为*的时候才可能成立
		for (int i = 1; i < n+1; i++)
		{
			if (p[i-1]=='*')
			{
				pd[0][i] = pd[0][i - 1];
			}
			else
			{
				pd[0][i] = false;
			}
		}

		for (int i = 1; i < m+1; i++)
		{
			for (int j = 1; j < n+1; j++)
			{
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?')              //由于字符串末尾有/0，所以即使空字符串也不违背上述规则
				{
					pd[i][j] = pd[i - 1][j - 1];
				}
				else if(p[j-1]=='*')
				{
					pd[i][j] = pd[i - 1][j] || pd[i][j - 1];//前者对应*代表多个字符，后者对应*为空字符串的情况
				}
				else
				{
					pd[i][j] = false;
				}
			}
		}
		return pd[m][n];  //不要将数组的大小和数组的小标混了写成pd[m+1][n+1]
	}
};
int main()
{
	string s = "aa", p = "a";
	SolutionA a;
	bool test=a.isMatch(s, p);
	cin.get();
}