/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
public:
    void solve(vector<vector<char>>& board) {
        /*
        m == board.length
        n == board[i].length
        1 <= m, n <= 200
        */
       int m=board.size(),n=board[0].size();
       if (n==0)
       {
           return;
       }
       vector<vector<int>> used(m,vector<int>(n,0));
       //从外围往内进行遍历
       //可以发现被包围的O与外围的O都没X隔开了，有点类似于417题中的洋流问题
       for (int i = 0; i < m; i++)
       {
           //左右两侧深度优先搜索
           dfs(board,used,i,0,m,n);
           dfs(board,used,i,n-1,m,n);
       }
       for (int i = 0; i < n; i++)
       {
           dfs(board,used,0,i,m,n);
           dfs(board,used,m-1,i,m,n);
       }
       //打好标记后只需要查看内圈哪个'O'没被标记过改为'X'即可
       for (int i = 1; i < m-1; i++)
       {
           for (int j = 1; j < n-1; j++)
           {
               //不遍历最外围
               if (board[i][j]=='O' && used[i][j]==0)
               {
                   board[i][j]='X';
               }
               
           }
       }
       return;
       
       
    }
    void dfs(vector<vector<char>>& board,vector<vector<int>> &used,
    int row,int column,const int &m,const int &n)
    {
        if (row<0 || row>m-1 || column<0 || column>n-1)
        {
            return;
        }
        if (used[row][column]==1 || board[row][column]=='X')
        {
            return;
        }
        //否则满足board[row][column]=='O' && board[row][column]==0
        used[row][column]=1;
        dfs(board,used,row+1,column,m,n);
        dfs(board,used,row-1,column,m,n);
        dfs(board,used,row,column+1,m,n);
        dfs(board,used,row,column-1,m,n);

        
    }
};
// @lc code=end

