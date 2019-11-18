//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1 :
//
//输入: ["flower", "flow", "flight"]
//	输出 : "fl"
//	示例 2 :
//
//	输入 : ["dog", "racecar", "car"]
//	输出 : ""
//	解释 : 输入不存在公共前缀。
//	说明 :
//
//	所有输入只包含小写字母 a - z 。
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int i = 0;	//字符串相同的个数
		int len = strs.size();
		bool loop_next = true;;
		if (len==1)
		{
			return strs[0];
		}
		if (len<1)
		{
			return "";
		}
		while (loop_next)     //string的最后一个字符是“\0”
		{
			for (int j = 1; j < len; j++)
			{
				if (strs[0][i]!=strs[j][i])
				{
					loop_next = false;//跳出循环
					break;
				}
				if (j==len-1)//说明第i位都相等，如果不相等的话在上面已经跳出
				{
					i++;	
				}
			}
			
			if (i!=0 && strs[0][i-1]== '\0')//以第一个字符串来对比，防止访问越界,注意要i-1,运行到这里时i指的是字符串相同的个数而不是字符串的下标，区分不同地方i的意义
				//下次类似的最好用两个变量表示，不容易混淆
				//果然还是分开探讨后，这里又漏了0-1=-1越界访问的情况,加一层逻辑与的判断,防止出现访问-1的情况
			{
				loop_next = false;
			}
		}
		if (i==0)	//没有公共前缀
		{
			return "";
		}
		else
		{
			//C++使用substr(begin,n)函数，为常函数，原函数中的数据的值不改变,begin为开始的位置，n是从开始的位置返回的位数。
			return strs[0].substr(0,i);
		}
	}
};
int main()
{
	vector<string> b = {"aaaaaaaaaaaaaaa",""};
	Solution a;
	a.longestCommonPrefix(b);
	cin.get();
}