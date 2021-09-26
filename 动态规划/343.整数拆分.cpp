// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem343.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0]=0,dp[1]=0;
        for (int i = 2; i <= n; i++)
        {
            int maxdp=0;
            for (int j = 1; j < i; j++)
            {
                maxdp=max(maxdp,max(dp[j]*(i-j),j*(i-j)));//这里解决的是dp[j]是否大于j的问题
                
            }
            dp[i]=maxdp;
        }
        return dp[n];
    }
};
// @lc code=end

