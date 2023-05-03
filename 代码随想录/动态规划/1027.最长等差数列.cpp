/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        auto [minnum,maxnum] =  minmax_element(nums.begin(),nums.end());
        int diff = *maxnum - * minnum;
        
        int ans = 1;
        for (int d = -diff; d <= diff; d++)
        {
            vector<int> dp(*maxnum+1,-1);
            for(auto num:nums)
            {
                if(int prev = num - d; prev >= *minnum && prev <= *maxnum && dp[prev]!= -1)
                {
                    dp[num] = max(dp[prev]+1 , 1);
                    ans = max(dp[num],ans);
                }
                dp[num] = max(dp[num],1);
            }
            
        }
        return ans;

    }
};
// @lc code=end

