// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem51.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
//皇后可以走横竖斜三个方向
class Solution {
public:
    vector<vector<int>> used;//判断当前的子能不能走,放2代表放了棋子，1代表是攻击范围
    vector<vector<string>> ans;
    int path;//用来判断现在摆放了几个皇后  
    vector<vector<string>> solveNQueens(int n) {
        //1<=n<=9
        if (n==1)
        {
            return {{"Q"}};
        }
        //因为是n*n的棋盘和n个棋子，所以满足条件的解法一定是每行放一个棋子
        //故只需要便利第一行就可
        used=vector<vector<int>>(n,vector<int>(n,0));
        for (int j = 0; j < n; j++)
        {
            dfs(0,j,n);
        } 
        return ans;
    };
    void dfs(int i,int j,int n)
    {   
        /*if (i>=n && j>=n)
        {
            return;
        }
        */
        if (used[i][j]!=0)
        {
            return;
        }
        path++;//放置一枚皇后
        vector<vector<int>> lastused=used;//用于回溯
        setattack(i,j,n);
        used[i][j]=2;//标识皇后的位置
        if (path==n)
        {
            vector<string> s_ans;
            string s="";
            for (auto row:used)
            {
                s="";
                for (auto column:row)
                {
                    if (column==2)
                    {
                        s+="Q";
                    }
                    else
                    {
                        s+=".";
                    }
                }
                s_ans.push_back(s);
            }
            ans.push_back(s_ans);
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                dfs(i+1,j,n);
            }
        }
        //回溯
        used=lastused;
        path--;
        return;
    };
    void setattack(int i,int j,int n)//设置攻击范围
    {
        for (auto row:used[i])//行置1
        {
            row=1;
        }
        for (int k=0;k<n;k++)//列置1
        {
            used[k][j]=1;
        }
        //斜对角只需要向下置1，因为是上面一行放好后才往下放，上面一行必定已经被占
        //左下角
        int row=i,column=j;
        while (row<n-1 && column>0)
        {
            used[++row][--column]=1;
        }
        row=i,column=j;
        while (row<n-1 && column<n-1)
        {
            used[++row][++column]=1;
        }  
    };
};
// @lc code=end

