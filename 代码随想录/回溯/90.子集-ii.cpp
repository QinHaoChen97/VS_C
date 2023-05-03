/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int numsLen=nums.size();
        sort(nums.begin(),nums.end());
        vector<bool> used(numsLen,false);
        backtracking(nums,0,used);
        return ans;
    }
    void backtracking(const vector<int> &nums, int pos, vector<bool> &used)
    {
        ans.emplace_back(path);
        if(pos>=nums.size())
        {
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            //防止同一层（第i个位置上）有重复的元素，需要先对nums进行排列
            if (i >= 1 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            else
            {
                path.emplace_back(nums[i]);
                used[i] = true; //分支搜索时将used[i]置为true
                backtracking(nums, i + 1, used);
                used[i] = false; //分支搜索完将进行层级搜索，将used[i]置为false
                //这样可以跳过相同的层
                path.pop_back();
            }
        }
    }
};
// @lc code=end
