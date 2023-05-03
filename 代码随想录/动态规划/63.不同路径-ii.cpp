/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
#include<iostream>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        for (int i = 0; i < row; i++)
        {
            if (obstacleGrid[i][0] != 1)
            {
                dp[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        for (int j = 0; j < column; j++)
        {
            if (obstacleGrid[0][j] != 1)
            {
                dp[0][j] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < column; j++)
            {
                if (obstacleGrid[i][j] != 1)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                cout<<i<<","<<j<<"="<<dp[i][j]<<endl;
            }
        }
        return dp[row - 1][column - 1];
    }
};
// @lc code=end
