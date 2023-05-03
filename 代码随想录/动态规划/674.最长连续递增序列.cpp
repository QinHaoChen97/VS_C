/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int numsLen=nums.size();
        if(numsLen==0)
        {
            return 0;
        }
        if(numsLen==1)
        {
            return 1;
        }
        vector<int> dp(numsLen,1);
        int result=1;
        for (int i = 1; i < numsLen; i++)
        {
            if(nums[i]>nums[i-1])
            {
                dp[i]=dp[i-1]+1;
                result=max(result,dp[i]);
            }
        }
        return result;
        
    }
};
// @lc code=end

