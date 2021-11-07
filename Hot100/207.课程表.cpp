// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem207.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        map<int, vector<int>> directed_graph; //有向图,这里其实用vector来写更好
        for (const auto &pre : prerequisites)
        {
            indegree[pre[0]]++;
            directed_graph[pre[1]].push_back(pre[0]);
        }
        int have_study = 0;
        queue<int> zero_indegree;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                zero_indegree.push(i);
            }
        }
        while (!zero_indegree.empty())
        {
            int course = zero_indegree.front();
            zero_indegree.pop();
            have_study++; //一门前置课程学习完成
            for (const auto &follow_course : directed_graph[course])
            {
                indegree[follow_course]--;
                if (indegree[follow_course] == 0)
                {
                    zero_indegree.push(follow_course);
                }
            }
        }
        return have_study==numCourses;
    }
};
// @lc code=end
