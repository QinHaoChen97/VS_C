/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //这道题贪心也可以
        int numsLen=nums.size();
        if(numsLen==1)
        {
            return  nums[0];
        }
        vector<int> dp(numsLen,0);
        dp[0]=nums[0];
        int result=dp[0];
        for (int i = 1; i < numsLen; i++)
        {
            if(dp[i-1]>=0)
            {
                dp[i]=dp[i-1]+nums[i];
            }
            else
            {
                dp[i]=nums[i];
            }
            result=max(result,dp[i]);
        }
        return result;
        
    }
};
// @lc code=end

