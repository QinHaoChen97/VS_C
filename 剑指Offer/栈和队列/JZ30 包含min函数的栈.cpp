// https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=23268&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//最小栈，之前在leetcode有做过
#include <stack>
using std::stack;
class Solution
{
private:
    stack<int> sta;
    stack<int> sta_min;

public:
    void push(int value)
    {
        sta.push(value);
        if (sta_min.empty())
        {
            sta_min.push(value);
        }
        else
        {
            if (value <= sta_min.top())
            {
                sta_min.push(value);
            }
            else
            {
                sta_min.push(sta_min.top());
            }
        }
    }
    void pop()
    {
        sta.pop();
        sta_min.pop();
    }
    int top()
    {
        return sta.top();
    }
    int min()
    {
        return sta_min.top();
    }
};