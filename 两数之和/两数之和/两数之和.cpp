#include<iostream>
#include<vector>
#include<map>
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
//该题哈希表要用到的函数知识储备
//map.count(Key)返回值为1或者0，1返回存在，0返回不存在，返回的是布尔类型的值，因为在map类型中所有的数据的Key值都是不同的，所以被count的数要么存在1次，要么不存在
//如果出现两个相同的键值，那么新加入的键值的value会覆盖旧的value,map中只允许有一个相同的键值
//-------------------------------------------------------------------------
//key 存放对应的数组值
//value 存放对应的数组的下标
//所以map[数组值]返回了该值对应在nums数组中的下标
class SolutionOne {
public:
 vector<int> twoSum(vector<int>& nums, int target) {
      
	    map<int,int> m;
        for(int i=0;i<(int)nums.size();i++)
        {
            int b=target-nums[i];
            if(m.count(b)){//count与find或者下标查找的不同之处需要了解，有则返回1，没有则返回0.
				return{ i,m[b] };
            }
            m[nums[i]]=i;
        }
		return{-1,-1};
    }
};

int main()
{
	vector<int> nums = { 1,1,2,5,9,8};
	SolutionOne A;
	vector<int> gettarget;
	gettarget= A.twoSum(nums, 3);
	cout << gettarget[0] << endl;
	cout << gettarget[1] << endl;
	return 0;
};