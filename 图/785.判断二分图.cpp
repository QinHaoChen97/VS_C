// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem785.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        //染色法
        int flag = 1;
        queue<int> q; //存放未染色的节点
        int length = graph.size();
        vector<int> cnt(length, 0);
        for (int i = 0; i < length; i++)
        {
            if (!graph[i].empty() && cnt[i]==0)
            {
                q.push(i);
            }
            while (!q.empty())
            {
                for (int i = q.size(); i > 0; i--) //将新的点加入
                {
                    int u = q.front();
                    for (auto v : graph[u])
                    {
                        if (cnt[v] == 0) //还没染过色
                        {
                            q.push(v);
                        }
                        else if (cnt[v] == flag) //和当前的节点已经染成一样的颜色
                        {
                            // cout<<"false"<<endl;
                            return false;
                        }
                    }
                    q.pop();
                    cnt[u] = flag;
                }
                //染完一轮就换一个颜色
                flag = (flag == 1 ? 2 : 1);
            }
        }

        return true;
    }
};
// @lc code=end
