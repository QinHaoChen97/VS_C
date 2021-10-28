/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
//看到种数 可以考虑动态规划
//https://leetcode-cn.com/problems/unique-binary-search-trees/solution/96-bu-tong-de-er-cha-sou-suo-shu-dong-ta-vn6x/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0); //dp[i]看成是[1,i]个数可以排列的二叉搜索树个数，不要在意数值，主要是个数
        //比如[5,6,7]和[1,2,3]的生成的二叉搜索树的个数是一样的
        dp[0]=1;
        dp[1]=1;
        for (int i = 2; i <= n; i++)
        {
           for (int j = 1; j <= i; j++)//以j作为二叉搜索树的头
           {
               dp[i]+=dp[j-1]*dp[i-j];
           }
           
        }
        return dp[n];
    }
};
// @lc code=end

