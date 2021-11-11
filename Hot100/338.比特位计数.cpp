// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem338.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 0;
        bool flag = false; //奇偶的翻转位
        for (int i = 1; i < n+1; i++)
        {
            if (flag) //是偶数
            {
                dp[i] = dp[i / 2]; //想象一下除以2就是右移去掉了一位
            }
            else //奇数
            {
                dp[i] = dp[i - 1] + 1; //奇数的最低位多一个1
            }
            flag = !flag;
        }
        return dp;
    }
};
// @lc code=end
