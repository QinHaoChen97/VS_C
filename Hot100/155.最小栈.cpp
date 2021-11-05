/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MinStack
{
private:
    stack<int> min_stack; //该栈的栈顶为当前存储元素的最小值
    stack<int> sta;       //普通的栈
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (sta.empty())
        {
            sta.push(val);
            min_stack.push(val);
        }
        else
        {
            sta.push(val);
            min_stack.push(min_stack.top() < val ? min_stack.top() : val);
        }
    }
    void pop()
    {
        sta.pop();
        min_stack.pop();
    }

    int top()
    {
        return sta.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};
/*
不用额外空间的做法。思路是栈里保存差值。 python3
class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_value = -1

    def push(self, x: int) -> None:
        if not self.stack:
            self.stack.append(0)
            self.min_value = x
        else:
            diff = x-self.min_value
            self.stack.append(diff)
            self.min_value = self.min_value if diff > 0 else x

    def pop(self) -> None:
        if self.stack:
            diff = self.stack.pop()
            if diff < 0:
                top = self.min_value
                self.min_value = top - diff
            #else:
            #    top = self.min_value + diff
            #return top

    def top(self) -> int:
        return self.min_value if self.stack[-1] < 0 else self.stack[-1] + self.min_value

    def getMin(self) -> int:
        return self.min_value if self.stack else -1
*/
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
