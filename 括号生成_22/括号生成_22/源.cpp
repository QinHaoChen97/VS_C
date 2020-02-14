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
//动态规划
/*
第 1 步：定义状态 dp[i]：使用 i 对括号能够生成的组合。

注意：每一个状态都是列表的形式。

第 2 步：状态转移方程：

i 对括号的一个组合，在 i - 1 对括号的基础上得到，这是思考 “状态转移方程” 的基础；
i 对括号的一个组合，一定以左括号 "(" 开始，不一定以 ")" 结尾。为此，我们可以枚举新的右括号 ")" 可能所处的位置，得到所有的组合；
枚举的方式就是枚举左括号 "(" 和右括号 ")" 中间可能的合法的括号对数，而剩下的合法的括号对数在与第一个左括号 "(" 配对的右括号 ")" 的后面，这就用到了以前的状态。
状态转移方程是：

dp[i] = "(" + dp[可能的括号对数] + ")" + dp[剩下的括号对数]
“可能的括号对数” 与 “剩下的括号对数” 之和得为 i - 1（感谢 @xuyik 朋友纠正了我的错误），故 “可能的括号对数” j 可以从 0 开始，最多不能超过 i， 即 i - 1；
“剩下的括号对数” + j = i - 1，故 “剩下的括号对数” = i - j - 1。
整理得：

dp[i] = "(" + dp[j] + ")" + dp[i- j - 1] , j = 0, 1, ..., i - 1
第 3 步： 思考初始状态和输出：

初始状态：因为我们需要 0 对括号这种状态，因此状态数组 dp 从 0 开始，0 个括号当然就是 [""]。
输出：dp[n] 。
这个方法暂且就叫它动态规划，这么用也是很神奇的，它有下面两个特点：

1、自底向上：从小规模问题开始，逐渐得到大规模问题的解集；

2、无后效性：后面的结果的得到，不会影响到前面的结果。

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class SolutionA {
public:
	vector<string> generateParenthesis(int n) {//vector容器第一个元素的位置为0，vector.at(0)
		if (n==0)
		{
			return{};
		}
		vector<vector<string>> all;
		vector<string> zero;
		zero.push_back("");
		vector<string> one;
		one.push_back("()");
		//动态规划初始值
		all.push_back(zero);
		all.push_back(one);
		for (int i = 2; i <= n; i++) //从第二项开始生成，注意是小于等于
		{
			vector<string> num;//用于存放第n组数据
			for (int j = 0; j <= i-1; j++)//dp[i] = "(" + dp[j] + ")" + dp[i- j - 1] , j = 0, 1, ..., i - 1,注意这里要小于等于
			{
				string cur;
				vector<string> mid;//dp[j]
				vector<string> right;//dp[i-j-1]
				mid = all.at(j);
				right = all.at(i - j - 1);
				for (auto curmid:mid)
				{
					for (auto curright : right)
					{
						cur += "(";
						cur += curmid;
						cur += ")";
						cur += curright;
						num.push_back(cur);
						cur = "";//将cur清空
					}
				}
			}
			all.push_back(num);
		}
		return all.at(n);
	}
};
int main()
{
	SolutionA a;
	a.generateParenthesis(3);
	cin.get();
}