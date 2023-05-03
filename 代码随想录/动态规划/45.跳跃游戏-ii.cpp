/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
#include <limits.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int numsLen=nums.size();
        vector<int> dp(numsLen,INT_MAX);
        dp[0]=0;
        for (int i = 1; i < numsLen; i++)
        {
            for (int j=i-1; j>=0; j--)
            {
                if(j+nums[j]>=i)
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[numsLen-1];
    }
};
// @lc code=end

