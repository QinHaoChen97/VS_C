// https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=23281&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//题目出的有问题，pop()只能在平均时间复杂度上能达到O（1）的条件
#include <stack>
using std::stack;
class Solution
{
public:
    void push(int node)
    {
        stack1.emplace(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            if (stack1.empty())
            {
                return -1; // 没有元素可以弹出
            }
            else
            {
                while (!stack1.empty())
                {
                    stack2.emplace(stack1.top());
                    stack1.pop();
                }
            }
        }
        //此时stack2不为空
        int ans = stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1; // stack1用于push
    stack<int> stack2; // stack2用于pop
};