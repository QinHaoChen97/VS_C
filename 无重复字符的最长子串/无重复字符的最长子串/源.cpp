//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1 :
//
//输入: "abcabcbb"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//	示例 2 :
//
//	输入 : "bbbbb"
//	输出 : 1
//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//	示例 3 :
//
//	输入 : "pwwkew"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


//滑动窗口法,窗口为半开半闭区间[head,tail)
#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int head = 0, tail = 0;//存储两个数字，分别指向子串的开头和子串的结尾，窗口为半开半闭区间[head,tail)
		int maxstr = 1;//存储最长子串的长度,设置为1的原因是当字符串只有一个字符的话那么最长的子串长度明显为1
		if (s.length()<=0)
		{
			return 0;
		}
		map<char, int> hash;//创建一hash表用于存储已经出现过的数字，key为char,key_value为对应的char的最新出现的位置
		for (int i = 0; i < int(s.length()); i++)
		{
			if (hash.count(s[i]))		//如果字符串中已经出现了
			{
				if (hash[s[i]]>=head) //如果此时hash[s[i]]大于等于head（加上等于号是因为初次更新时若刚好是在首位重复，那么head=0，此时hashs[i]也为0），那么该重复的元素是出现在了当前的滑动窗口中，那么更新此时的head
				{
					if (maxstr<(tail - head))  //在更新head之前，首先判断是否出现了长度更长的子串，是则更新子串的长度
					{
						maxstr = tail - head;
					}
					head = hash[s[i]] + 1; //更新子串的头，更新的位置应该为相同位置往后一位	
				}
				tail++;	  //尾部的长度每次滑动都需要更新
			}
			else
			{
				tail++;  //尾部的长度每次滑动都需要更新
			}
			hash[s[i]] = i;			//更新map，如果有相同的key，那么新的key_value会覆盖旧的
		}
		if (maxstr < (tail - head))  //最后需要再更新一次最长长度，因为当窗口滑动到字符串最后如果子串没有重复便不会更新最长长度
		{
			maxstr = tail - head;
		}
		return maxstr;
	}
};

int main()
{
	string h = " ";
	cout << h.length() << endl;
}