/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (auto ch : s)
        {
            if(ch == 'c')
            {
                if(sta.size() < 2)
                {
                    return false;
                }
                if(sta.top() == 'b')
                {
                    sta.pop();
                }
                else
                {
                    return false;
                }
                if(sta.top() == 'a')
                {
                    sta.pop();
                }
                else
                {
                    return false;
                }
                
            }
            else
            {
                sta.push(std::move(ch));
            }
            
        }
        if(sta.empty())
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

