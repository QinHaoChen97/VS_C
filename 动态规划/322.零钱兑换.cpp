// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem322.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        int coin_size=coins.size();
        dp[0]=0;//0用0个硬币
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coin_size; j++)
            {
                int coin=coins[j];
                if (coin>i)
                {
                    continue;
                }
                if (dp[i-coin]!=INT_MAX)
                {
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
                
                
                
                
            }
            
        }
        if (dp[amount]==INT_MAX)
        {
            return -1;
        }
        
        return dp[amount];

    }
};
// @lc code=end

