// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem279.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//https://leetcode-cn.com/problems/perfect-squares/solution/wan-quan-ping-fang-shu-by-leetcode-solut-t99c/
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1); //n+1个数，包括dp[0]=0,为初始条件
        //dp[i]表示i需要用完全平方数来表示的最小个数
        //dp[i]=min(min_dp,dp[i-j*j]);j<sqrt(i)
        //为了得到dp[i]，需要先求得dp[0],dp[1]......dp[i-1]
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int min_dp = INT_MAX - 1;
            for (int j = 1; j * j <= i; j++)
            {
                min_dp = min(min_dp, dp[i - j * j]);
            }
            dp[i] = min_dp + 1; //dp[i]等于dp[i-j*j]+j*j,j*j代表一个完全平方数，所以加1
        }
        return dp[n];
    }
};
// @lc code=end
