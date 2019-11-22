//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//
//说明 :
//
//s 可能为空，且只包含从 a - z 的小写字母。
//p 可能为空，且只包含从 a - z 的小写字母，以及字符 .和 *。
//示例 1 :
//
//	输入 :
//	s = "aa"
//	p = "a"
//	输出 : false
//	解释 : "a" 无法匹配 "aa" 整个字符串。
//	示例 2 :
//
//	输入 :
//	s = "aa"
//	p = "a*"
//	输出 : true
//	解释 : 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//	示例 3 :
//
//输入:
//s = "ab"
//p = ".*"
//输出 : true
//	解释 : ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
//	示例 4 :
//
//	输入 :
//	s = "aab"
//	p = "c*a*b"
//	输出 : true
//	解释 : 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
//	示例 5 :
//
//	输入 :
//	s = "mississippi"
//	p = "mis*is*p*."
//	输出 : false
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//使用递归，逐步缩减string s和string p的长度
		if (s.length()==0 && p.length()==0)
		{
			return true;
		}
		if (p.length()==0 && s.length()!=0)
		{
			return false;
		}
		//由于这里没有对s.length()是否等0做判断，所以下面要裁剪s的时候要注意看是否需要加粤界的判断条件
		if (p.length()==1)	//剩一个字符的情况
		{
			if (p[0]=='.' && s.length()>0)	//匹配任一字母
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else if (p[0]=='*')//只有在*号在p的一开始才会出现这种情况，直接去掉该*号，因为它前面没有字母，没有意义
			{
				return isMatch(s, p.substr(1));
			}
			else
			{
				if (p[0]==s[0])  
				{
					return isMatch(s.substr(1), p.substr(1));
				}
			}
		}
		if (p.length()>1)
		{
			if (p[1]=='*')	//特殊情况
			{
				if ((p[0]==s[0] )|| (p[0]=='.' && s.length()>0) )  //p[0]==s[0]已经暗含了s长度大于0
				{
					return isMatch(s.substr(1), p) || isMatch(s, p.substr(2)); //第二种情况对应的是.*后面还带有字母，这个地方是这道题递归的精髓,注意这里是或
					//想一想，如果你不确定s="aaaacc",p=".*cc",则.*应该等于"aaaa"，但是运算到这里的时候实际上你并不清楚要在这时候把.*去掉，那么怎么办呢？
					//把所有的可能都囊括进去，即做了一个分支，左边的情况就像一棵树展开，把.*应该在什么时候去掉尝试了一遍，最后刚好有一个分支能返回一个true，而这里用的是或逻辑，有一个true就说明有一条路是对的，即是能匹配上的
					//               "aaaacc"                              ".*cc"
					//          	"aaacc" ".*cc"                                   "aaaacc" "cc" 右边这条分支最后会return false
					//        "aacc" ".*cc"           "aaacc" "cc" 右边同理
					// "acc"  ".*cc"       "aacc"  "cc" 右边同理
					//continue--------------------

					//也因为这里的递归要展开这么多种可能的原因，程序的运行效率必然会变慢
				}
				else//字母+* 且s[0]!=p[0]
				{
					return isMatch(s, p.substr(2));
				}
			}
			else//p[1]!='*'，按普通情况判断p[0]即可
			{
				if (p[0] == '.' && s.length()>0)	//匹配任一字母
				{
					return isMatch(s.substr(1), p.substr(1));
				}
				else if (p[0] == '*')//只有在*号在p的一开始才会出现这种情况，直接去掉该*号，因为它前面没有字母，没有意义
				{
					return isMatch(s, p.substr(1));
				}
				else
				{
					if (p[0] == s[0])
					{
						return isMatch(s.substr(1), p.substr(1));
					}
				}
			}
		}
		return false; //防止Leetcode编译报错
	}
};
int main()
{
	string s = "a", p = ".*..a*";
	Solution a;
	a.isMatch(s, p);
	cin.get();
}