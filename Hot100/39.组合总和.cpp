// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
    vector<int> combination;
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        combination.clear();
        ans.clear();
        sort(candidates.begin(),candidates.end());//先做排序，后面判断的时候可以剪枝
        int candidates_len = candidates.size();
        int sum = 0;
        backtracking(candidates, target, candidates_len, sum,0);
        return ans;
    }
    ///@param pos 是为了防止出现重复的答案，限制每次从candidates中的查找位置只能从当前位置开始(需要对candidates先升序排序)
    void backtracking(const vector<int> &candidates, const int &target, const int &length, int sum,int pos)
    {
        for (int i = pos; i < length; i++)
        {
            sum += candidates[i];
            if (sum > target)
            {
                return;//剪枝，因为candidates是升序的，所以后面的元素都不满足条件了
            }
            else if (sum == target)
            {
                combination.push_back(candidates[i]);
                ans.push_back(combination);
                combination.pop_back();
                return;//剪枝，因为candidates是升序的，所以candidates[i]后面的元素必定使sum>target
            }
            else
            {
                // sum<target
                combination.push_back(candidates[i]);
                backtracking(candidates, target, length, sum,i);
                combination.pop_back();
            }
            sum -= candidates[i];
        }
    }
};
// @lc code=end
