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
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
    vector<string> combinations;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

public:
    vector<string> letterCombinations(string digits)
    {
        combinations.clear();
        if (digits.empty())
        {
            return combinations;
        }

        string ans_s = "";
        int len = digits.size();
        for (auto s : phoneMap[digits[0]])
        {
            ans_s.push_back(s);
            backtracking(1, digits, ans_s, len);
            ans_s.pop_back();
        }
        return combinations;
    }
    void backtracking(int pos, const string &digits, string &ans_s, const int &len)
    {
        if (pos == len)
        {
            combinations.push_back(ans_s);
            return;
        }
        for (auto s : phoneMap[digits[pos]])
        {
            ans_s.push_back(s);
            backtracking(pos+1, digits, ans_s, len);
            ans_s.pop_back();
        }
        return;
    }
};
// @lc code=end
