/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int s_length = s.size();
        vector<vector<bool>> dp(s_length,vector<bool>(s_length, false));
        int count=0;
        for (int j = 0; j < s_length; j++) //只计算j>=i部分，即动态规划矩阵的右上角
        {
            for (int i = 0; i <= j; i++)
            {
                if (s[i]==s[j] && (j-i<2 || dp[i+1][j-1]))
                {
                    dp[i][j]=true;
                    count++;
                }
                
            }
            
        }
        return count;
    }
};
// 还有一种中心拓展算法
// https://leetcode-cn.com/problems/palindromic-substrings/solution/liang-dao-hui-wen-zi-chuan-de-jie-fa-xiang-jie-zho/
// @lc code=end
