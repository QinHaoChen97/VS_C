//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
//
//L   C   I   R
//E T O E S I I G
//E   D   H   N
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
//
//请你实现这个将字符串进行指定行数变换的函数：
//
//string convert(string s, int numRows);
//示例 1:
//
//输入: s = "LEETCODEISHIRING", numRows = 3
//	输出 : "LCIRETOESIIGEDHN"
//	示例 2 :
//
//	输入 : s = "LEETCODEISHIRING", numRows = 4
//	输出 : "LDREOEIIECIHNTSG"
//	解释 :
//
//	L     D     R
//	E   O E   I I
//	E C   I H   N
//	T     S     G
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//借鉴了官方参考给出的方法
class Solution {
public:
	string convert(string s, int numRows) {
		bool down = false; //判断往上还是往下填充，想象Z字型
		int line = 0;//行数
		if ((int)s.size()<=numRows || numRows==1)	//这里必须要判断numRows==1的情况，原因有两点，1是等于1时没有变换的必要，2是与下面的算法冲突，因为此时n-1==0
			//即头尾是相同的位置，故需要再多一个判断if(n-1==0)，不如直接在一开始便排除
		{
			return s;
		}
		vector<string> Z_change(numRows);	//将vector[i]看作是一行
		for (auto str:s)
		{
			//先填充再判断下一位要填充的行
			Z_change[line] += str;	//将对应字符放入对应的行					
			if (line == 0 || line == numRows - 1)//到达"Z"的头或者尾部
			{
				down = !down;
			}
			if (down)	//判断下一位需要填充的行，down=true则是填下一行
			{
				line++;
			}
			else//反之应该填充上一行.line--
			{
				line--;
			}
		}
		string z;
		for (auto str:Z_change)	//将三行拼接起来
		{
			z += str;
		}
		return z;
	}
};
int main()
{
	Solution A;
	string a = "AB";
	A.convert(a,1);
	cin.get();
}