// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem301.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
#include <vector>
#include <string>
#include<iostream>
using std::string;
using std::vector;
//https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shan-chu-wu-xiao-de-gua-hao-by-leetcode-9w8au/
class Solution
{
    vector<string> ans;

public:
    vector<string> removeInvalidParentheses(string s)
    {
        ans.clear();
        int leftremove = 0;
        int rightremove = 0;

        //寻找要删除的括号数
        for (const auto &i : s)
        {
            if (i == '(')
            {
                leftremove++;
            }
            if (i == ')')
            {
                if (leftremove == 0)
                {
                    rightremove++;
                }
                else
                {
                    leftremove--;
                }
            }
        }
        back_tracking(s, 0, leftremove, rightremove);
        return ans;
    }
    void back_tracking(const string s, int start, int leftremove, int rightremove)
    {
        if (leftremove == 0 && rightremove == 0)
        {
            std::cout<<s<<std::endl;
            if (is_vilid(s))
            {
                ans.emplace_back(s);
            }
        }
        for (int i = start; i < s.size(); i++)
        {
            //剪枝
            if (i != start && s[i] == s[i - 1])
            {
                continue;
            }
            //剩余元素个数无法满足要删除的括号个数
            if (leftremove + rightremove > s.size() - i)
            {
                return;
            }
            if (s[i] == '(' && leftremove > 0)
            {
                back_tracking(s.substr(0, i) + s.substr(i + 1), i, leftremove - 1, rightremove);
            }
            if (s[i] == ')' && rightremove > 0)
            {
                back_tracking(s.substr(0, i) + s.substr(i + 1), i, leftremove, rightremove - 1);
            }
        }
    }
    bool is_vilid(const string s)
    {
        int cnt=0;
        for (const auto &i : s)
        {
            if (i=='(')
            {
                cnt++;
            }
            if (i==')')
            {
                cnt--;
            }
            if (cnt<0)
            {
                return false;
            }
        }
        return cnt==0; //不是return true,'('数目过多也是错误的
        
    }
};
// @lc code=end
