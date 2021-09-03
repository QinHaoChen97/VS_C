// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem221.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
//参考题解
//https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //按照参考题解的想法，提前预设外部的一圈0以满足
        //动态规划的要求
        //其中，dp(i, j) 是以 matrix(i - 1, j - 1) 为 右下角 的正方形的最大边长。
        //所以结果应该是max(dp(i,j))^2
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j]=='1')
                {
                    dp[i+1][j+1]=min(dp[i][j+1],min(dp[i+1][j],dp[i][j]))+1;
                }
                
            }
        }
        int max=0;
        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                if (max<dp[i][j])
                {
                    max=dp[i][j];
                }
                
            }
            
        }
        return max*max;
        
    }
};
// @lc code=end
