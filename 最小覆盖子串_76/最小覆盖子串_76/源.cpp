/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

 示例 1：

 输入：s = "ADOBECODEBANC", t = "ABC"
 输出："BANC"
 示例 2：

 输入：s = "a", t = "a"
 输出："a"

*/

#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size()<t.size()) //如果t字符个数大于s，那么肯定是找不到的
		{
			return string();
		}
		map<char, int> scan_t,scan_s; //scan_t用于存储t的键值对，key char是存在于t中的字符，value int是出现的次数，同理scan_s用于存储s的
		int t_len = t.size();
		//先扫描子串t,统计其中出现的字符及每个字符出现的次数
		for (int i = 0; i < t_len; i++)
		{
			if (!scan_t.count(t[i]))
			{
				scan_t.insert(pair<char,int>(t[i],1));
				scan_s.insert(pair<char,int>(t[i],0));
			}
			else
			{
				scan_t[t[i]]++;
			}
		}
		
		int s_len = s.size();

		int left=0,right; //左右指针，用于模仿滑动窗口
		/*
		对字符串做预处理，如果是s=xxxabc,t=abc,可以忽略掉前面的xxx
		*/
		while (left<s_len && scan_t.find(s[left]) == scan_t.end())
		{
			left++;
		}
		right = left - 1;
		
		int ansL = left-1, len = INT_MAX,flag=ansL; //flag用于判断是否不存在最小子串
		while (right<s_len)
		{
			if (scan_t.find(s[++right]) != scan_t.end()) //说明当前的字符在字符串里
			{
				++scan_s[s[right]];
			}
			while (check(scan_t,scan_s) && left<=right)
			{
				if (right - left + 1 < len)  //如果当前的重复字符串更短
				{
					len = right - left + 1;
					ansL = left;
				}
				//滑动左边的窗口
				if (scan_t.find(s[left])!=scan_t.end())
				{
					--scan_s[s[left]];
				}
				left++;
			}
		}
		return ansL==flag?string():s.substr(ansL, len);
	}
	bool check(map<char, int> &scan_t,map<char, int> &scan_s)  //用于判断当前的子串是否满足条件
	{
		for (const auto &p : scan_t)
		{
			if (scan_s[p.first]<p.second)
			{
				return false;
			}
		}
		return true;
	}
};
int main()
{
	string s = "a", t = "aa";
	Solution a;
	a.minWindow(s, t);
	cin.get();
}