/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<=2)
        {
            return 0;
        }
        int diff=nums[1]-nums[0];
        vector<int> dp(nums_size,0);//dp代表这个数属于等差数列的话会增加的等差数列个数
        //显然dp[0],dp[1]=0;
        dp[0]=0;
        dp[1]=0;
        for (int i = 2; i < nums_size; i++)
        {
            if (nums[i]-nums[i-1]==diff)
            {
                dp[i]=dp[i-1]+1;//动态规划
                //可以发现新增加一个数满足等差数列条件增加的等差子数列个数等于dp[i-1]+1
            }
            else
            {
                diff=nums[i]-nums[i-1];
            }
            
            
        }
        int count=0;
        for (const auto &d:dp)
        {
            count+=d;
        }
        return count;
        
    }
};
// @lc code=end

