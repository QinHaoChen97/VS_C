// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem309.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //dp[i][j]代表今天结束后的最大收益
        /*
        由于我们最多只能同时买入（持有）一支股票，并且卖出股票后有冷冻期的限制，因此我们会有三种不同的状态：

        我们目前持有一支股票，对应的「累计最大收益」记为 f[i][0]；

        我们目前不持有任何股票，并且处于冷冻期中，对应的「累计最大收益」记为 f[i][1]；

        我们目前不持有任何股票，并且不处于冷冻期中，对应的「累计最大收益」记为 f[i][2]。
        这里的「处于冷冻期」指的是在第 ii 天结束之后的状态。也就是说：如果第 ii 天结束之后处于冷冻期，那么第 i+1i+1 天无法买入股票。

        作者：LeetCode-Solution
        链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/
        来源：力扣（LeetCode）
        */
        int day = prices.size();
        vector<vector<int>> f(day, vector<int>(3, 0));
        //初始化
        f[0][0] = -prices[0]; //f[0][1]=0,f[0][2]=0
        for (int i = 1; i < day; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[day - 1][1], f[day - 1][2]);
    }
};
// @lc code=end
