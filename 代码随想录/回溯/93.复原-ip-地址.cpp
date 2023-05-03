// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
    vector<string> path;
    vector<vector<string>> ans;
    vector<string> result;
    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0);
        for (int i = 0; i < ans.size(); i++)
        {
            string tmp = "";
            for (int j = 0; j < 4; j++)
            {
                tmp += ans[i][j] + '.';
            }
            tmp.pop_back();
            result.emplace_back(tmp);
        }

        return result;
    }
    void backtracking(const string &s, int pos)
    {
        if (path.size() == 3)
        {
            string str(s.begin() + pos, s.end());
            if (is_legal(str)) //还剩最后一个数，看是否符合规则
            {
                path.emplace_back(str);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        if (pos >= s.size())
        {
            return;
        }
        for (int i =1; i <= s.size(); i++)
        {
            if(pos+i>=s.size())
            {
                return;
            }
            string str=s.substr(pos,i);
            if(is_legal(str))
            {
                path.emplace_back(str);
                backtracking(s,pos+i);
                path.pop_back();
            }
            else
            {
                break;
            }
            
        }
    }
    bool is_legal(string &str)
    {
        if (str.empty() || (str[0] == '0' && str.size() > 1))
        {
            return false;
        }
        int tmp = 0;
        for (int i = 0; i < str.size(); i++)
        {
            tmp = tmp * 10 + str[i] - '0';
            if (tmp > 255)
            {
                return false;
            }
        }

        if (tmp >= 0 && tmp <= 255)
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
