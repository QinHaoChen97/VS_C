/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include<stack>
using namespace std;
class MinStack {
    stack<int> sta;
    stack<int> minsta;
public:
    MinStack() {

    }
    
    void push(int val) {
        sta.push(val);
        if(minsta.empty())
        {
            minsta.push(val);
            return;
        }
        int tmp=minsta.top();
        if (tmp>val)
        {
            minsta.push(val);
        }
        else
        {
            minsta.push(tmp);
        }

    }
    
    void pop() {
        sta.pop();
        minsta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return minsta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

