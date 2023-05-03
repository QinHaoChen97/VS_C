/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int pricesLen=prices.size();
        if(pricesLen<=1)
        {
            return 0;
        }
        vector<vector<int>> dp(pricesLen,vector<int>(2,0));
        //dp[i][0]，当天没股票，dp[i][1]当天有股票
        dp[0][1]=-prices[0];
        for (int i = 1; i < pricesLen; i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
            dp[i][1]=max(dp[i-1][1],dp[i][0]-prices[i]);
        }
        return max(dp[pricesLen-1][0],dp[pricesLen-1][1]);
    }
};
// @lc code=end

