/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> mono_stack;
        int length = temperatures.size();
        vector<int> ans(length);
        mono_stack.push(0); //压入第一天，这样代码的逻辑比较好写
        for (int i = 1; i < length; i++)
        {
            while (!mono_stack.empty())
            {
                int data = mono_stack.top(); //获得栈顶元素
                if (temperatures[i]>temperatures[data])
                {
                    mono_stack.pop();
                    ans[data]=i-data;//得到升温的天数
                }
                else
                {
                    break;
                }
                
            }
            //无论是否空了都要将新的元素压入栈
            mono_stack.push(i);
        }
        //所有元素都进行了压栈处理后，还会有剩余元素，至少最后一天的温度肯定还在栈中
        //做收尾处理
        while (!mono_stack.empty())
        {
            int data=mono_stack.top();
            ans[data]=0;
            mono_stack.pop();
        }
        return ans;
        
    }
};
// @lc code=end
