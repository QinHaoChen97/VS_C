/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
    int ans;

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        ans = 0;
        vector<vector<int>> tree(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                tree[manager[i]].emplace_back(i);
            }
        }
        dfs(headID, 0, tree, informTime);
        return ans;
    }
    void dfs(int head, int time, vector<vector<int>> &tree, vector<int> &informTime)
    {
        if (tree[head].size() == 0)
        {
            ans = max(time, ans);
        }
        time += informTime[head];
        for (int i = 0; i < tree[head].size(); i++)
        {
            dfs(tree[head][i], time, tree, informTime);
        }
    }
};
// @lc code=end
