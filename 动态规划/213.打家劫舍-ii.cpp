/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 2)
        {
            int max = 0;
            for (int i = 0; i < len; i++)
            {
                if (nums[i] > max)
                {
                    max = nums[i];
                }
            }
            return max;
        }
        vector<int> dp(len);
        return max(maxrob(dp,0,len-2,nums),maxrob(dp,1,len-1,nums));
    }
    int maxrob(vector<int>& dp,int start,int end,vector<int> &nums)
    {
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for (int i = start+2; i <= end; i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[end];
    }
};
// @lc code=end
