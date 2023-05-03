// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem123.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, 0)));
        // dp[i][j][k],i为天数，j为目前为第(j+1)笔交易，k为第几笔交易的买还是卖阶段
        // dp[i][j][0]为(没股票)，dp[i][j][1]为(有股票)
        // dp[i][2][1]用不上
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = 0;
        dp[0][1][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0][0] = dp[i - 1][0][0];
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][1] + prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] - prices[i]);
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] + prices[i]);
        }
        return dp[prices.size() - 1][2][0];
    }
};
// @lc code=end
