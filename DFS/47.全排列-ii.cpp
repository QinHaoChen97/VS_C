/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int nums_size=nums.size();
        if (nums_size==0)
        {
            return {};
        }
        sort(nums.begin(),nums.end());//排序
        vector<int> used(nums_size,0);
        vector<int> path;
        vector<vector<int>> ans;
        backtracking(used,path,ans,nums,nums_size);
        return ans;
    }
    void backtracking(vector<int> &used, vector<int> &path, vector<vector<int>> &ans, vector<int> &nums,
    const int &nums_size)
    {
        if (path.size()==nums_size)
        {
           ans.push_back(path);
        }
        for(int i=0;i<nums_size;i++)
        {   
            //剪枝，依赖于对nums的排列
            //https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/
            if (i>0 && nums[i]==nums[i-1] && used[i-1]==0)
            {
                continue;
            }
            if (used[i]==1)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i]=1;
            backtracking(used,path,ans,nums,nums_size);
            path.pop_back();
            used[i]=0;
        }
        
    }
};
// @lc code=end
//在46题的基础上加上set 
/*
class Solution
{
public:
    set<vector<int>> anss;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int nums_len = nums.size();
        if (nums_len <= 1)
        {
            return {nums};
        }
        vector<bool> used(nums_len, false); //判断是否使用过这个数，vector<boo>不要随便用
        vector<vector<int>> ans;
        vector<int> path;
        backtracking(used, path, ans, nums);
        for(auto w:anss)
        {
            ans.push_back(w);
        }
        return ans;
    }
    void backtracking(vector<bool> &used, vector<int> path, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (path.size() == nums.size()) //找到一种排列方式
        {
            anss.insert(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) //其实算是一种暴力的解法
        {
            if (used[i] == true)
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(used, path, ans, nums);
            //找到一种排列方式后回溯
            path.pop_back();
            used[i] = false;
        }
    }
};
*/