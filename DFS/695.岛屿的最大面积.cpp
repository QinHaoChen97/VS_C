// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem695.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //grid非空
        int m=grid.size(),n=grid[0].size();
        int maxgrid=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]!=0)
                {
                    maxgrid=max(area(grid,i,j,m,n),maxgrid);
                }
            }
            
        }
        return maxgrid;
    }
    /*
    递归查找岛屿
    */
    int area(vector<vector<int>>&grid,int i,int j,int &row,int &column){
        if (i>=0&&i<row&&j>=0&&j<column)//防止越界
        {
            if (grid[i][j]!=0)
            {   
                grid[i][j]=0;//扫描过的岛屿置0防止重复操作
                return 1+area(grid,i-1,j,row,column)+area(grid,i+1,j,row,column)+
                area(grid,i,j-1,row,column)+area(grid,i,j+1,row,column);//对东南西北四个方向进行搜索
            }
        }
        return 0;
        
    }
};
// @lc code=end

