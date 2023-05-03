/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> sta;
        for (int i = 0; i < height.size(); i++)
        {
            if (sta.empty())
            {
                sta.push(i);
            }
            
        }
        
    }
};
// @lc code=end

