/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <limits.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            int num = i * i;
            if (num < n)
            {
                nums.emplace_back(num);
            }
            else if (num == n)
            {
                return 1;
            }
            else
            {
                break;
            }
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        //无序排列，所以先遍历物品再遍历背包
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = nums[i]; j < n + 1; j++)
            {
                // if(dp[j-nums[i]]==INT_MAX)
                // {
                //     continue;
                // }
                dp[j] = min(dp[j - nums[i]] + 1, dp[j]);
                // dp[j] = min(dp[j],dp[j-nums[i]+1]) 会报
                //整数溢出，因为会出现INT_MAX+1
                //但上面这么写不会，奇怪了
            }
        }
        return dp[n];
    }
};
// @lc code=end
