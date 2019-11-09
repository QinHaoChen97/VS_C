//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//说明：
//
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//示例 1:
//
//输入: [2, 2, 1]
//	输出 : 1
//	示例 2 :
//
//	输入 : [4, 1, 2, 1, 2]
//	输出 : 4


//线性复杂度划重点
#include<iostream>
#include<vector>
#include<map>
using namespace std;
//线性复杂度——想到哈希表？
//提交之后能正确通过，但占用的内存和运行效率都很低
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> one_map;
		for (int i = 0; i < nums.size(); i++)//扫描一遍数组
		{
			if (one_map.count(nums[i]))		//如果表中出现这个数字，那么将他的value+1
			{
				one_map[nums[i]]++;		//这里改为删除这个键值会更好，这样最后只会剩下一个键值，即为所求答案
			}
			else
			{
				one_map[nums[i]] = 1;
			}
		}
		for (int i = 0; i < (nums.size()); i++)
		{
			if (one_map[nums[i]]==1)
			{
				return nums[i];
			}
		}
		return 0;		//注意这里要return，避免空数组没有返回值
	}
};

//异或算法，有点6
//方法 4：位操作
//什么是异或运算(xor)：1 xor 1 = 0, 0 xor 0 = 0, 1 xor 0 = 1, 0 xor 1 = 1
//知道了什么是异或运算之后，就可以得出任意数字异或其自身等于0的结论。比如数字5，其二进制是101，那么就有101 xor 101 = 0
//知道了什么是异或运算之后，就可以得出任意数字异或0等于其本身的结论。
//位运算与顺序无关，即a xor b = b xor a, a xor b xor a = a xor a xor b = b

class SolutionB {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0;//用于异或 0 xor 1=1;
		for (int i = 0; i < nums.size(); i++)
		{
			a = a ^ (nums[i]);	//异或
		}
		return a;
	}
};
//效率的确会更好，内存占用也更小
int main()
{}