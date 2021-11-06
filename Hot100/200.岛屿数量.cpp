// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int count;
    int row_len;
    int col_len;
public:
    int numIslands(vector<vector<char>> &grid)
    {
        row_len = grid.size(), col_len = grid[0].size();
        vector<vector<int>> used(row_len, vector<int>(col_len, 0));//如果直接将遍历过的陆地置为0，那么可以不需要used！
        //https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
        count = 0;
        for (int i = 0; i < row_len; i++)
        {
            for (int j = 0; j < col_len; j++)
            {
                if (used[i][j]==0 && grid[i][j]=='1') //找到一个未遍历过的岛屿,注意岛屿是用char存放，不是int
                {
                    count++;
                    dfs(used,grid,i,j);
                }   
            }
        }
        return count;
    }
    void dfs(vector<vector<int>> &used, vector<vector<char>> &grid,int i,int j)
    {
        if (i<0 || i>=row_len || j<0 || j>=col_len)//防止越界
        {
            return;
        }
        if (used[i][j]==1 || grid[i][j]=='0') //已经遍历过当前陆地或者当前为水
        {
            return;
        }
        
        //当前是已统计的岛屿上未遍历过的陆地，往上下左右四个方向继续搜索其他未遍历的土地
        used[i][j]=1;
        dfs(used,grid,i-1,j);
        dfs(used,grid,i+1,j);
        dfs(used,grid,i,j-1);
        dfs(used,grid,i,j+1);
        return;
    }
};
// @lc code=end
