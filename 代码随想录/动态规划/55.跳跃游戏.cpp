/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=0;
        int i=0;
        while(i<=maxJump && maxJump<nums.size())
        {
            maxJump=max(maxJump,i+nums[i]);
            i++;
        }
        if(maxJump>=nums.size()-1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};
// @lc code=end

