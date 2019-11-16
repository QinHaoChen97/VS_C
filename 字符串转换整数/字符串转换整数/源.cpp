//请你来实现一个 atoi 函数，使其能将字符串转换成整数。
//首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
//当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
//该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
//注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
//在任何情况下，若函数不能进行有效的转换时，请返回 0。
//说明：
//假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回  INT_MAX(231 − 1) 或 INT_MIN(−231) 。
//
//示例 1 :
//
//输入: "42"
//	输出 : 42
//	示例 2 :
//
//	输入 : "   -42"
//	输出 : -42
//	解释 : 第一个非空白字符为 '-', 它是一个负号。
//	我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 - 42 。
//	示例 3 :
//
//输入: "4193 with words"
//	输出 : 4193
//	解释 : 转换截止于数字 '3' ，因为它的下一个字符不为数字。
//	示例 4 :
//
//输入: "words and 987"
//	输出 : 0
//	解释 : 第一个非空字符是 'w', 但它不是数字或正、负号。
//	因此无法执行有效的转换。
//	示例 5 :
//
//输入: "-91283472332"
//	输出 : -2147483648
//	解释 : 数字 "-91283472332" 超过 32 位有符号整数范围。
//	因此返回 INT_MIN(−231) 。
#include<iostream>
#include<string>
#include <sstream> 
using namespace std;
//0-9的ascii码为48-57,+为43，-为45，空格为32
class Solution {
public:
	int myAtoi(string str) {
		bool positive = true;	//用于存储值的正负
		bool Not_num = false;//当该标志位为true时若下一位不是数字则直接break;
		int n_atoi=0;
		for (auto ch:str) //不要忘记加auto
		{
			if (ch==32)	
			{
				if (Not_num)
				{
					break;
				}
				continue;	//空格
			}
			else if (ch==43)
			{
				if (Not_num)
				{
					break;
				}
				Not_num = true;
			}
			else if (ch==45)
			{
				if (Not_num)
				{
					break;
				}
				Not_num = true;
				positive = false;
			}
			else if(ch>=48 && ch<=57)
			{
				Not_num = true;
				if (positive) //是正数，则和INT_MAX比较
				{
					if (n_atoi>INT_MAX/10 || (n_atoi==INT_MAX/10 && (int)ch-'0'>7))	//判断是否溢出，这里需要将ch转为对应的数字而不是ascii码
					{
						return INT_MAX;
					}
					n_atoi = n_atoi * 10 + ((int)ch - '0'); //这里需要转换整数再加减，否则有可能出现溢出的情况！因为运算是从左到右的	
				}
				else
				{
					if (n_atoi<INT_MIN/10 || (n_atoi==INT_MIN/10 && (int)ch-'0'>8))	//这里也可以写成-(int)ch-'0'<-8
					{
						return INT_MIN;
					}
					n_atoi = n_atoi * 10 - ((int)ch - '0');  //注意这里应当是减去,因为是负数
 				}
			}
			else//其他条件都不满足题意，直接退出循环
			{
				break;
			}
		}
		return n_atoi;
	}
};


//使用C++标准字符串IO库<sstream>中的istringstream函数
//网上的牛逼解法
//#include<sstreaam>
//相关类的用法见https://blog.csdn.net/Sophia1224/article/details/53054698
class Solution {
public:
	int myAtoi(string str) {
		int digit = 0;
		istringstream is(str);
		is >> digit;
		return digit;
	}
};



