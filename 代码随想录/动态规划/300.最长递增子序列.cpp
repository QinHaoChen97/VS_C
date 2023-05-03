/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int numsLen=nums.size();
        vector<int> dp(numsLen,1);
        for (int i = 1; i < numsLen; i++)
        {
            int tmp=nums[i];
            for (int j = i-1; j >= 0; j--)
            {
                if(tmp>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            
        }
        return *(max_element(dp.begin(),dp.end()));
        
    }
};
// @lc code=end
