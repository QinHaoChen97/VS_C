//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//
//输入 : "babad"
//	输出 : "bab"
//	注意 : "aba" 也是一个有效答案。
//	示例 2：
//
//	输入 : "cbbd"
//	输出 : "bb"
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/longest-palindromic-substring
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		string maxstrseg="";//存储最长的子字符回文串,可以使用substr(start,num)函数对字符串进行截取start为起始位置，num为从截取位置开始截取的个数
		int str_num = s.length();
		if (str_num<=1)		//排除空字符串和单字符串
		{
			return s;
		}
		//使用中心展开法，分别对奇数回文串和偶数回文串进行遍历
		//先对奇数回文串进行遍历，奇数回文串的中心为单个子串
		for (int i = 1; i < str_num; i++)		
		{
			int mid = i;	//中心
			int right = mid, left = mid;	//指向回文串两头
			while (1)
			{
				if ((right + 1) > (str_num-1) || (left - 1) < 0)	//检查是否越界,strnum不是最大下标，str_num-1才是最大下标
				{
					break;
				}
				else
				{
					right++;
					left--;
					if (s[right]!=s[left])
					{
						right--;		//退回
						left++;
						break;
					}
				}
			}
			string strseg = s.substr(left, right-left+1);
			if (strseg.length()>maxstrseg.length())
			{
				maxstrseg = strseg;
			}
		}
		//偶数回文串，中心为偶数
		for (int i = 1; i < str_num; i++)	//已经排除了单字符，可以直接从第二位算起
		{
			int mid_left = i - 1, mid_right = i;
			int left = mid_left, right = mid_right;
			if (s[mid_left]!=s[mid_right])	//先判断偶数对称中心是否符合
			{
				continue;
			}
			else
			{
				while (1)
				{
					if (left<0 || right>(str_num - 1)) //检查越界
					{
						left++;	//退回
						right--;
						break;
					}
					if (s[left] != s[right])  //检查是否符合回文特征
					{
						left++;	//退回
						right--;
						break;
					}
					else
					{
						left--;
						right++;
					}
				}
			}
			string strseg = s.substr(left, right-left+1);
			if (strseg.length()>maxstrseg.length())
			{
				maxstrseg = strseg;
			}
		}

		return maxstrseg;
	}
};

int main()
{
	Solution a;
	string h = "ac";
	string b = a.longestPalindrome(h);
	while (1)
	{

	}
	return 0;
}