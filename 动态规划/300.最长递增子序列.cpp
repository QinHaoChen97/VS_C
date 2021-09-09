// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> dp(nums_size,1);//dp[i]代表当前nums[0]~nums[i]序列的最长递增子序列长度
        for (int i = 1; i < nums_size; i++)
        {
            for (int j = i; j >0 ; j--)//这里正序找和逆序找其实都可以
            {
                if (nums[i]>nums[j-1])
                {
                    dp[i]=dp[i]>(dp[j-1]+1)?dp[i]:(dp[j-1]+1);
                }
                
            }
            
            
        }
        int max=1;
        for (const auto &d:dp)
        {
            if (d>max)
            {
                max=d;
            }
            
        }
        return max;
        
    }
};
// @lc code=end

//O(nlog(n))的方法可以看这个解释
//https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/