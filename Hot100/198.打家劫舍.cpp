/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        //dp[i][0] 代表第i个房屋不偷时能取得的最大效益
        //dp[i][1] 代表第i个房屋偷时能取得的最大效益
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
        */
       
       //由于只需要前一天偷和不偷的信息，所以可以不用维护一个二维数组，维护两个数就行
       int nums_len=nums.size();
       int steal=nums[0];
       int not_steal=0;
       for (int i = 1; i < nums_len; i++)
       {
           int middle=steal;
           steal=not_steal+nums[i];
           not_steal=max(middle,not_steal);
       }
       return max(steal,not_steal);
    }
};
// @lc code=end

