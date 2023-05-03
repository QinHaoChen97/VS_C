/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
//这道题给的prices可能等于0，所以要排除极端
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if(prices.size()<=1)
        {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(k * 2 + 1, 0));
        // dp[i][j],j奇数为有股票，偶数没股票
        for (int j = 1; j < 2 * k + 1; j += 2)
        {
            dp[0][j] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j < 2 * k + 1; j++)
            {
                // dp[i][0]一直等于0，可以忽略
                if (j % 2 == 1) // 奇数为买入股票
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
// @lc code=end
