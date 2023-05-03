/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);  //dp[i]表示当前的金额可以有几种组合
        dp[0]=1;
        sort(coins.begin(),coins.end());
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j < amount+1; j++)
            {
                dp[j]+=dp[j-coins[i]];
            }
            
        }
        
        return dp[amount];
        
    }
};
// @lc code=end

