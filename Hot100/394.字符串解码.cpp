// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem394.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> sta_char;
        string ans = "";
        for (const auto &ch : s)
        {
            if (ch == '[' || (ch >= '0' && ch <= '9'))
            {
                sta_char.push(string(1, ch));
            }
            else if (ch == ']')
            {
                string part = "";
                while (sta_char.top() != "[")
                {
                    part = sta_char.top() + part;
                    sta_char.pop();
                }
                // sta_char.top()=='['
                sta_char.pop();
                // sta_char.top()此时为数字，可能不只一位
                int count = 1; //个 十 百 千......位
                int k = 0;
                while (!sta_char.empty() && sta_char.top() >= "0" && sta_char.top() <= "9")
                {
                    k = count * stoi(sta_char.top()) + k;
                    count *= 10;
                    sta_char.pop();
                }
                string ans_part="";
                while (k-- > 0) //重复k次
                {
                    ans_part += part;
                }
                if (!sta_char.empty())
                {
                    sta_char.push(ans_part);
                }
                else
                {
                    ans += ans_part;
                }
            }
            else // 为英文字母
            {
                if (!sta_char.empty()) //栈不空说明这些英文字母包含在中括号里
                {
                    sta_char.push(string(1, ch));
                }
                else
                {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
