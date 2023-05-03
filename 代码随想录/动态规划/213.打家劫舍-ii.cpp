/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        //dp[i]为当前能偷到的最大金额
        vector<int> dp(nums.size());
        //第一天偷的情况
        dp[0]=nums[0];
        dp[1]=nums[0];
        for (int i = 2; i < nums.size()-1; i++) //第一天偷，最后一天就不能偷了
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        int first_rob=dp[nums.size()-2];
        cout<<first_rob<<endl;
        //第一天不偷
        dp[0]=0;
        dp[1]=nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        int second_rob=dp[nums.size()-1];
        
        return max(first_rob,second_rob);
        

    }
};
// @lc code=end

