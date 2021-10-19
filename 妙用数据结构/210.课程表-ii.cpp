// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem210.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;
class Solution
{
private:
    const int done = 1;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> in(numCourses,0);//统计当前节点的入度
        vector<vector<int>> Coursesmap(numCourses,vector<int>());//构建连通图
        for (auto pre:prerequisites)
        {
            in[pre[0]]++;
            Coursesmap[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i]==0)
            {
                q.push(i);
            }
            
        }
        if (q.empty())
        {
            return vector<int>();
        }
        vector<int> ans;
        while (!q.empty())
        {
            int course=q.front();
            q.pop();
            ans.push_back(course);
            for(auto cour:Coursesmap[course])
            {
                in[cour]--;
                if (in[cour]==0) //入度为0 加入到队列中
                {
                    q.push(cour);
                }
                
            }
        }
        if (ans.size()==numCourses)
        {
            return ans;
        }
        return vector<int>();
        
        
        
        
        
        
    }
};
// @lc code=end
