// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem934.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    queue<pair<int,int>> points;//用于bfs
    int shortestBridge(vector<vector<int>>& grid) {
        //2 <= grid.length == grid[0].length <= 100
        //grid[i][j] == 0 或 grid[i][j] == 1
        //一定存在两座岛
      
        int m=grid.size();
        int n=grid[0].size();
        bool flag=false;    
        //找一座岛
        for (int i = 0; i < m; i++)
        {
            if (flag)
            {
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]==1)
                {
                    flag=true;//跳出外圈循环
                    dfs(grid,m,n,i,j);
                    break;
                }
            }
        }
        //找到岛了，用bfs进行遍历
        int count=0;//需要翻转的数目
        while (!points.empty()) 
        {
            count++;
            int po_size=points.size();
            while (po_size--)
            {
                //取元素
                auto [row,column]=points.front();
                points.pop();
                if (grid[row][column]==2)
                {
                    continue;
                }
                
                if (row>0)
                {
                    if (grid[row-1][column]==1)
                    {
                        return count;
                    }
                    if (grid[row-1][column]==0)
                    {
                        points.push({row-1,column});
                    }
                }
                if (row<m-1)
                {
                    if (grid[row+1][column]==1)
                    {
                        return count;
                    }
                    if (grid[row+1][column]==0)
                    {
                        points.push({row+1,column});
                    }
                }
                if (column>0)
                {
                    if (grid[row][column-1]==1)
                    {
                        return count;
                    }
                    if (grid[row][column-1]==0)
                    {
                        points.push({row,column-1});
                    }
                }
                if (column<n-1)
                {
                    if (grid[row][column+1]==1)
                    {
                        return count;
                    }
                    if (grid[row][column+1]==0)
                    {
                        points.push({row,column+1});

                    }
                }
                 grid[row][column]=2;//标志2防止重复入列
            }
            
        }
        return count;
    }

    void dfs(vector<vector<int>>& grid,int m,int n,int row,int column)
    //用于找岛屿
    {
        if (row<0 || row==m || column<0 || column==n || grid[row][column]==2)
        {
            return;
        }
        if (grid[row][column]==1)
        {
            grid[row][column]=2;
        }
        else//grid[row][column]==0
        {
            points.push({row,column});//岛屿外围的空白处
            return;//空白处可能连接另外一座岛，不能通过空白处继续找
        }
        dfs(grid,m,n,row+1,column);
        dfs(grid,m,n,row-1,column);
        dfs(grid,m,n,row,column+1);
        dfs(grid,m,n,row,column-1);
    }
};
// @lc code=end

