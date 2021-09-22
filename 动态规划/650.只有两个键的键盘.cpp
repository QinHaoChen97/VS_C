// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem650.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1, INT_MAX); //dp(n+1)为了标号匹配，dp(n)其实也是可以的
        dp[0] = 0, dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i; //Copy 'A'并粘贴i-1次,最多需要这么多次
            /*for (int j = 2; j <= i/2; j++)
            {
                if (i%j==0)//j可以整除i0
                {
                    int count=i/j;
                    dp[i]=min(dp[i],dp[j]+count);//count为复制一次并粘贴count-1次=1+count-1
                }
                
            }*/

            //优化写法
            //https://leetcode-cn.com/problems/2-keys-keyboard/solution/zhi-you-liang-ge-jian-de-jian-pan-by-lee-ussa/
            //看这里的细节
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    dp[i] = min(dp[i], dp[j] + i / j);
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
