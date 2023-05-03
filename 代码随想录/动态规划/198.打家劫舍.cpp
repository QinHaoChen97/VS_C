/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
       int numsLen=nums.size();
       vector<vector<int>> dp(numsLen,vector<int>(2,0));
       //dp[i][0]代表不偷这间房能取的最大值，dp[i][1]代表偷这间房能取的最大值

       dp[0][0]=0;
       dp[0][1]=nums[0];
       for (int i = 1; i < numsLen; i++)
       {
           dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
           dp[i][1]=max(dp[i-1][0]+nums[i],dp[i-1][1]);
       }
       return max(dp[numsLen-1][0],dp[numsLen-1][1]);
    }
};
// @lc code=end
