/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX); //dp[i]代表凑成当前硬币所需要的最少硬币个数
        //硬币的次序是无所谓的，所以要先遍历物品，再遍历背包
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j < amount+1; j++)
            {
                if(dp[j-coins[i]]==INT_MAX)
                {
                    continue;
                }
                else
                {
                    dp[j]=min(dp[j-coins[i]]+1,dp[j]);
                }
                
            }
            
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
        
    }
};
// @lc code=end

