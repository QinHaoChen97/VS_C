/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int wiggleMaxLength(vector<int>& nums) {
        int numsLen=nums.size();
        vector<vector<int>> dp(numsLen,vector<int>(2));
        dp[0][0]=dp[0][1]=1; //dp[i][0] 下降 dp[i][1] 上升
        for (int i = 1; i < numsLen; i++)
        {
            dp[i][0]=dp[i-1][0];
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]<nums[j])
                {
                    dp[i][0]=max(dp[j][1]+1,dp[i][0]);
                    break;
                }
            }
            dp[i][1]=dp[i-1][1];
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i][1]=max(dp[j][0]+1,dp[i][1]);
                    break;
                }
            }
        }
        return max(dp[numsLen-1][0],dp[numsLen-1][1]);
    }
};
// @lc code=end

