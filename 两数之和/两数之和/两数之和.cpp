#include<iostream>
#include<vector>
using namespace std;
//两数之和
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例 :
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {//暴力解法,O(n^2)
		int length = nums.size();
		for (int i = 0; i < length; i++)
		{
			for (int j = i+1; j < length; j++)	//两两配对
			{
				if (nums[i]+nums[j]==target)
				{
					return{ i,j };
				}
			}
		}
		return{ 0 };
	}
};
int main()
{
	vector<int> nums = { 1,2,3,4 };
	Solution test;
	vector<int> end=test.twoSum(nums, 4);
	cout << end[0] << endl;
	cout << end[1] << endl;
	return 0;
}