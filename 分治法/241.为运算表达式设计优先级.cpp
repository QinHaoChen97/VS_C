// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem241.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        int length = expression.size();
        int number = 0;
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            count++;
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                number = (expression[i] - '0') + number * 10;
            }
            else
            {
                break;
            }
        }
        //判断是否string是一个数
        if (count == length)
        {
            return {number};
        }
        vector<int> ans = {};
        for (int i = 0; i < length; i++)
        {
            //以运算符作为分隔符
            if ((expression[i] >= '0' && expression[i] <= '9'))
            {
                continue;
            }
            vector<int> result1 = diffWaysToCompute(expression.substr(0, i));//这里应该是i而不是i+1，不要把运算符包含进来，否则会出现套娃
            //如2-1-，会一直重复输入2-1-
            vector<int> result2 = diffWaysToCompute(expression.substr(i + 1));
            for (auto res1 : result1)
            {
                for (auto res2 : result2)
                {
                    ans.push_back(caculate(res1, expression[i], res2));
                }
            }
        }

        return ans;
    }
    int caculate(int res1, char op, int res2)
    {
        switch (op)
        {
        case '+':
            return res1 + res2;
        case '-':
            return res1 - res2;
        case '*':
            return res1 * res2;
        }
        return -1;
    }
};
// @lc code=end
