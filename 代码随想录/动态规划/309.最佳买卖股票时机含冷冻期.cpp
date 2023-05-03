/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int pricesLen = prices.size();
        if (pricesLen <= 1)
        {
            return 0;
        }
        vector<vector<int>> dp(pricesLen, vector<int>(3, 0));
        // j==0,当天不卖出股票（无股票），j==1，有股票，j==2，当天卖出股票（无股票但第二天冷冻）
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < pricesLen; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max(dp[pricesLen - 1][0], dp[pricesLen - 1][2]);
    }
};
// @lc code=end
