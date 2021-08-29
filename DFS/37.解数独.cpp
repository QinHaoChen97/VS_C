// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        row=vector<vector<int>>(m,vector<int>(n,0));
        column=vector<vector<int>>(n,vector<int>(m,0));
        nine= vector<vector<vector<int>>>(3,vector<vector<int>>(3,vector<int>(9,0)));
        
        //标记使用过和未使用过的数字
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j]=='.')
                {
                    mspace.emplace_back(i,j);//两种写法都可以，这样会比较高效
                    //mspace.push_back({i,j});
                }
                else
                {
                    int digit=board[i][j]-'0'-1;
                    row[i][digit]=1;
                    column[j][digit]=1;
                    nine[i/3][j/3][digit]=1;
                }
                
            }
            
        }
        dfs(board,0);
        
    }
    void dfs(vector<vector<char>>& board,int pos)
    {
        if (pos==mspace.size())//说明所有的格子都放了数字且符合规则,pos是从0开始的，size-1的时候即满
        {
            valid=true;
            return;
        }
        auto [i,j]=mspace[pos];
        for (int k = 0; k < 9 && !valid; k++)//valid为true之后已经找到答案，可以结束回溯了
        {
            if (row[i][k]==1 || column[j][k]==1 || nine[i/3][j/3][k]==1)
            {
                continue;
            }
            row[i][k]=1;
            column[j][k]=1;
            nine[i/3][j/3][k]=1;
            board[i][j]=k+'0'+1;
            dfs(board,pos+1);
            row[i][k]=0;
            column[j][k]=0;
            nine[i/3][j/3][k]=0;
            //board[i][j]='.';  加上这个是错的，因为一定会回溯这一步，加上去之后一定是变回原样
            //board[i][j]放的不是'.'也没有关系，通过
            //row[i][k]==1 || column[j][k]==1 || nine[i/3][j/3][k]==1来判断这个位置的数是否使用即可
        }
        
        
    }

private:
    vector<vector<int>> row;
    vector<vector<int>> column;
    vector<vector<vector<int>>> nine;
    vector<pair<int,int>> mspace;
    bool valid=false;
};
// @lc code=end

