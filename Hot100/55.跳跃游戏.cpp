// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem55.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int nums_length = nums.size();
        bool nozero = true;
        for (int i = 0; i < nums_length; i++)
        {
            if (nums[i] == 0)
            {
                nozero = false;
                break;
            }
        }
        if (nozero)
        {
            return true; //因为是非负数组，所以如果全都不为0那么最后一个下标肯定可以到达
        }
        vector<int> dp(nums_length, 0); //避免使用vector<bool>，用0,1来表示bool值
        dp[0] = 1;
        //这样写中间其实出现了大量的重复计算，在动态规划的基础上进行改进使用贪心算法，效率会更高
        //只维护跳的最远的数组
        //https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
        for (int i = 0; i < nums_length; i++)
        {
            if (dp[i]==1)
            {
                for (int cnt = 1; cnt <= nums[i]; cnt++)
                {
                    if (i+cnt<nums_length)
                    {
                        dp[i+cnt]=1;
                    }
                    else if(i+cnt==nums_length)
                    {
                        return true;
                    }
                    else//i+cnt>nums_length
                    {
                        break;
                    }
                }
            }
            else//如果当前位置都没法到达，那么之后的位置肯定也无法到达
            {
                break;
            }
            
        }
        return dp[nums_length-1];
    }
};
// @lc code=end
