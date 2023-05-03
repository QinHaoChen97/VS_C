// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<vector<char>> num_ch;
    int ditgits_len;
    vector<string> letterCombinations(string digits)
    {
        ditgits_len = digits.size();
        if (ditgits_len==0)
        {
            return vector<string>(0);
        }
        if (dig)
        {
            /* code */
        }
        
        
        num_ch.resize(10);
        //初始化
        num_ch[2] = {'a', 'b', 'c'};
        num_ch[3] = {'d', 'e', 'f'};
        num_ch[4] = {'g', 'h', 'i'};
        num_ch[5] = {'j', 'k', 'l'};
        num_ch[6] = {'m', 'n', 'o'};
        num_ch[7] = {'p', 'q', 'r', 's'};
        num_ch[8] = {'t', 'u', 'v'};
        num_ch[9] = {'w', 'x', 'y', 'z'};
        unordered_set<string> ans;
        string path = "";
        
        backtracking(digits, 0, path, ans);
        return vector<string>(ans.begin(),ans.end());
    }
    void backtracking(const string &digits, int start, string &path, unordered_set<string> &ans)
    {
        if (start >= ditgits_len)
        {
            ans.insert(path);
            return;
        }
        int num = digits[start]-'0';
        for (int i = 0; i < num_ch[num].size(); i++) //遍历当前数字的字符
        {
            path += num_ch[num][i];
            backtracking(digits, start + 1, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end
