// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem417.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start

#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int m,n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return vector<vector<int>> {};
        }
        this->m=matrix.size(),this->n=matrix[0].size();
        //注意矩阵初始化的写法
        vector<vector<int>> p_martix(m,vector<int>(n,0));//能到太平洋的
        vector<vector<int>> a_martix(m,vector<int>(n,0));//能到大西洋的
        vector<vector<int>> ans;
        for (auto i = 0; i < m; i++)
        {
            DFS(matrix,p_martix,i,0);//~左边的太平洋
            DFS(matrix,a_martix,i,n-1);//*右边的大西洋
        }
        for (auto j = 0; j < n; j++)
        {
            DFS(matrix,p_martix,0,j);//~上边的太平洋
            DFS(matrix,a_martix,m-1,j);//*下边的大西洋
        }
        for (int i = 0; i < m; i++)//找出能同时流入两个洋的位置
        {
            for (int j = 0; j < n; j++)
            {
                if (p_martix[i][j] && a_martix[i][j])
                {
                    ans.push_back(vector<int>{i,j});
                }
                
            }  
        }
        return ans;
        
        
        
    }
    void DFS(vector<vector<int>> &matrix,vector<vector<int>> &judge,int i,int j)
    {
        if (judge[i][j])//说明已经扫描过,从海洋到陆地肯定是1，后续的就需要判断
        {
            return;
        }
        judge[i][j]=1;
        if (i>0 && matrix[i][j]<=matrix[i-1][j])//往上走
        {
            DFS(matrix,judge,i-1,j);
        }
        if (i<m-1 && matrix[i][j]<=matrix[i+1][j])//往下走
        {
            DFS(matrix,judge,i+1,j);
        }
        if (j>0 && matrix[i][j]<=matrix[i][j-1])//往左走
        {
            DFS(matrix,judge,i,j-1);
        }
        if (j<n-1 && matrix[i][j]<=matrix[i][j+1])//往右走
        {
            DFS(matrix,judge,i,j+1);
        }
        
    }
};

// @lc code=end

