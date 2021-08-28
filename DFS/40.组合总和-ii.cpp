// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        int count = 0;
        for (const auto &i : candidates) //统计小于target的数
        {
            if (i <= target)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        int sum = 0;
        vector<int> used(count, 0);
        for (int i = 0; i < count; i++)
        {
            dfs(candidates, target, sum, used, i, count);
            int j = i;
            while (i < count - 1 && candidates[j] == candidates[i + 1]) //剪枝，如果
            //出现相同的数字，由于经过排序，此时已经前面的计算已经将其包含进去，不需要重复计算
            {
                i++;
            }
        }

        return ans;
    }
    void dfs(vector<int> &candidates, int target, int &sum, vector<int> &used, int pos,const int &count)
    {
        if (sum + candidates[pos] > target)
        {
            return;
        }
        if (sum + candidates[pos] == target)
        {
            path.push_back(candidates[pos]);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        //sum + candidates[pos] < target
        sum += candidates[pos];
        path.push_back(candidates[pos]);
        used[pos] = 1;
        for (int i = pos + 1; i < count; i++)
        {
            if (candidates[i] == candidates[i - 1] && used[i - 1] == false) //剪枝，类似47题
            {
                continue;
            }
            dfs(candidates, target, sum, used, i, count);
        }
        //回溯
        sum -= candidates[pos];
        path.pop_back();
        used[pos] = 0; return;
    }
};
// @lc code=end
