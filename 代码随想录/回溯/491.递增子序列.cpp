/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> path;
    set<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int numsLen = nums.size();
        backtracking(nums, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    void backtracking(const vector<int> &nums, int pos)
    {
        if (path.size() >= 2)
        {
            ans.insert(path);
        }
        if (pos >= nums.size())
        {
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            if (path.size() == 0)
            {
                path.emplace_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
            else
            {
                if (nums[i] >= path[path.size() - 1]) //看分支是否是递增序列
                {
                    path.emplace_back(nums[i]);
                    backtracking(nums, i + 1);
                    path.pop_back();
                }
                else
                {
                    continue;
                }
            }
        }
    }
};
// @lc code=end
