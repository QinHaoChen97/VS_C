/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for (int i = 3; i < n+1; i++)
        {
            int tmp=0;
            for (int j = 1; j <= i; j++)
            {
                //以j作为根结点
                tmp+=dp[j-1]*dp[i-j];
            }
            dp[i]=tmp;
        }
        return dp[n];
        
        
    }
};
// @lc code=end

