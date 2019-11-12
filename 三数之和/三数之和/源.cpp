#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

//自己码的尝试一，在250/313超时了
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());		//先做一次排序，这对后续去除重复项能方便很多
		vector<vector<int>> thisum;
		int length = nums.size();
		map<int, int> thimap;	//key放对应的值，value放序号
		if (length<=2)
		{
			return thisum;
		}
		for (int i = 0; i < length-2; i++)
		{
			thimap.clear();	//清空当前的哈希表
			int seg = 0 - nums[i];
			for (int j = i+1; j < length; j++)	//从当前值的下一个开始
//之后用两数之和的算法
			{
				if (thimap.count(seg-nums[j]))	//如果哈希表中存在对应的值,则将三个值推入
				{
					vector<int> vec;
					vec.push_back(nums[i]);		
					vec.push_back(seg - nums[j]);//说明存在着这个值，直接放入便好
					vec.push_back(nums[j]);
					thisum.push_back(vec);

				}
				thimap[nums[j]] = j;//将当前元素放入图中
			}
		}
		//排除重复解,可以做但又是很复杂的工程，效率太低
		int siz = thisum.size();
		for (int i = 0; i < siz; i++)
		{
			for (int j = i+1; j < siz; j++)
			{
				if (thisum[i][0]==thisum[j][0])
				{
					if (thisum[i][1] == thisum[j][1])
					{
						if (thisum[i][2] == thisum[j][2])
						{
							thisum.erase(thisum.begin() + j);	//删除重复
							siz = thisum.size();//更新循环长度
							j--;//由于删除了一个元素，故接下来的元素代替了原先的位置，所以需要j--
						}
					}
				}
			}

		}
		return thisum;
	};
};
class SolutionA{
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());//先排序，偏于去重
		vector<vector<int>> thisum;
		int length = nums.size();
		if (length<=2)
		{
			return{};
		}
		for (int i = 0; i < length-2; i++)		//先固定一位，length-2时已不满足三位的条件
		{	
			if (nums[i]>0)	//已经从小到大排序，故nums[i]>0之后已不满足条件
			{
				return thisum;
			}
			int l, r;//左右指针
			if (i>0&&nums[i]==nums[i-1])		//去重,注意这里不要再加上i++,在for循环里面已经有隐含的操作了
			{
				continue;
			}
			else
			{
				l = i + 1, r = length - 1;
			}
			while (r>l)		//指针碰撞时退出
			{
				if (nums[i] + nums[l] + nums[r] == 0)
				{
					thisum.push_back(vector<int>{nums[i], nums[l], nums[r]});
					while (r>l && nums[l]==nums[l+1])	//去除重复项
					{
						l++;
					}
					while (r>l && nums[r]==nums[r-1])
					{
						r--;
					}
					l++, r--;
				}
				else if (nums[i] + nums[l] + nums[r] < 0)
				{
					l++;  //整体小于0，说明需要增大，故左指针右移
					continue;
				}
				else if (nums[i] + nums[l] + nums[r] > 0)
				{
					r--;  //整体大于0，说明需要减小，故右指针左移
				}
			}
		}
		return thisum;
	}
};





int main()
{
	SolutionA a;
	vector<int> b = { -4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 };
	a.threeSum(b);
}
