/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
//暴搜会超时
//使用0/1背包一维数组的写法
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum=0;
		int numsLen=nums.size();
		for (const auto& num:nums)
		{
			sum+=num;
		}
		if(sum%2==1)
		{
			return false;
		}
		int target=sum/2;
		vector<bool> dp(target+1,false);
		dp[0]=true;
		sort(nums.begin(),nums.end());
		for(int i=0;i<numsLen;i++)
		{
			for (int j = target; j >=0; j--)
			{
				if(nums[i]>j)
				{
					break;
				}
				else
				{
					dp[j]=dp[j] || dp[j-nums[i]];
				}
			}
			if(dp[target]==true)
			{
				return true;
			}
		}
		return false;
		
	}

};
// @lc code=end

