/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> path;
        dfs(s, 0, path);
        return ans;
    }
    vector<string> ans;
    void dfs(const string &s, int start, vector<string> &path)
    {
        if (path.size() == 4)
        {
            if (start==s.size())
            {
                string tmp = "";
                for (const auto &str : path)
                {
                    tmp = tmp + str + ".";
                }
                tmp.pop_back();
                ans.emplace_back(std::move(tmp));
            }
            return;
        }
        if (start >= s.size())
        {
            return;
        }
        if (s[start] == '0') //首字母为0
        {
            path.emplace_back("0");
            dfs(s, start + 1, path);
            path.pop_back();
        }
        else
        {
            for (int i = 1; i <= 3 && (start + i - 1 < s.size()); i++)
            {
                string tmp = s.substr(start, i);
                int num = stoi(tmp);
                if (num > 255)
                {
                    continue;
                }
                else
                {
                    path.emplace_back(tmp);
                    dfs(s, start + i, path);
                    path.pop_back();
                }
            }
        }
    }
};
// @lc code=end
