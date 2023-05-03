/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map> //记录每个机场已经到达过哪个机场
using namespace std;
class Solution
{
public:
    vector<string> ans;
    int placeCount;
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, map<string, int>> m; //(起点，(终点，航班数))
        for (const auto &ticket : tickets)
        {
            m[ticket[0]][ticket[1]]++;
        }
        placeCount = tickets.size() + 1;
        ans.push_back("JFK");
        backtracking(m, "JFK");
        return ans;
    }
    bool backtracking(unordered_map<string, map<string, int>> &m, string src)
    {
        if (ans.size() == placeCount)
        {
            return true;
        }
        for (auto &p : m[src])
        {
            if(p.second==0)
            {
                continue;
            }
            p.second--;
            ans.emplace_back(p.first);
            if (backtracking((m), p.first))
            {
                return true;
            }
            ans.pop_back();
            p.second++;
        }
        return false;
    }
};
// @lc code=end
