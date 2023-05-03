/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include<vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1); //dp[n]也可以，只是为了逻辑上方便
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for (int i = 3; i < n+1; i++)
        {
            int left=1,right=i-1;
            int maxtmp=0;
            while (left<=right)
            {
                maxtmp=max(maxtmp,max(left*right,left*dp[right]));
                left++;
                right--;
            }
            dp[i]=maxtmp;
            std::cout << i<<"="<<dp[i] << std::endl;
        }
        return dp[n];
        
    }
};
// @lc code=end

