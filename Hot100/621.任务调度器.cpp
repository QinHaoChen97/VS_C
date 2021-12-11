// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem621.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::unordered_map;
using std::vector;
//逻辑是对的，但太复杂
//https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
//这里采用贪心算法
//最大桶算法可以大大降低复杂度
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n==0)
        {
            return tasks.size();
        }
        
        vector<int> m(26, 0);
        for (const auto &task : tasks)
        {
            m[task - 'A'] += 1;
        }

        std::sort(m.begin(), m.end(), greater<int>()); //从大到小排序
        int count = 0;                                 //统计未使用的字母的种类
        int ans_time = 0;
        for (const auto &i : m)
        {
            if (i > 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        while (count > n)
        {
            auto it=m.begin();
            for (int i = 0; i < n+1; i++)
            {
                (*it)--;
                if (*it==0)
                {
                    it=m.erase(it); //erase返回的是原来被删除位置的下一位
                    count--;
                }
                else
                {
                    it++;
                }

                ans_time++;
            }
            std::sort(m.begin(), m.end(), greater<int>()); //前面的数可能因为被使用而导致存在的次数小于后面的
            //所以需要重新排序
            
        }
        while (count>0)
        {
            //每一轮的组成为：事件->事件->(n-count)*(待命)
            int current_count=count;
            for (int i = count-1; i >=0; i--)
            {
                m[i]--;
                ans_time++;
                if (m[i]==0)
                {
                    count--;
                }
            }
            if (count==0)
            {
                break;
            }
            ans_time=ans_time-current_count+n+1;
        }
        

        return ans_time;
    }
};
// @lc code=end
