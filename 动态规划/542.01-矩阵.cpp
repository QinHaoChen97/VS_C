// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem542.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int row = mat.size(), column = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(column, INT_MAX - 1));
        //做两次动态规划,左上到右下，右下到左上
        //左上到右下
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    continue;
                }
                if (i > 0)
                {
                    ans[i][j] = ans[i][j] <= ans[i - 1][j]+1 ? ans[i][j] : ans[i - 1][j]+1;
                }
                if (j > 0)
                {
                    ans[i][j] = ans[i][j] <= ans[i][j - 1]+1 ? ans[i][j] : ans[i][j - 1]+1;
                }
            }
        }
        //右下到左上
        for (int i = row - 1; i >= 0; i--)//注意这里是大于等于
        {
            for (int j = column - 1; j >= 0; j--)
            {
                if (i < row - 1)
                {
                    ans[i][j] = ans[i][j] <= ans[i + 1][j]+1 ? ans[i][j] : ans[i + 1][j]+1;
                }
                if (j < column - 1)
                {
                    ans[i][j] = ans[i][j] <= ans[i][j + 1]+1 ? ans[i][j] : ans[i][j + 1]+1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
