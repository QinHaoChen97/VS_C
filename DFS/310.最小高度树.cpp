// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem310.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//验证了最终剩下节点即为最小高度树根节点的合理性
//https://leetcode-cn.com/problems/minimum-height-trees/solution/yong-shu-de-zhi-jing-zheng-ming-bfs-by-a-6kvp/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1)
        {
            return {0};
        }
        if (n==2)
        {
            return {0,1};
        }
        vector<int> degree(n,0);
        vector<vector<int>> map(n,vector<int>());//生成图
        for (auto const &edge:edges)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        queue<int> Q;
        //初始化队列
        for (auto i = 0; i < n; i++)
        {
            if (degree[i]==1)
            {
                Q.push(i);
            }
        }
        while (n>2)
        {
            int size=Q.size();
            n-=size;
            while (size--)//从度为1的节点开始删除
            {
                int q=Q.front();
                Q.pop();
                degree[q]--;//该节点被删除，度减1
                for (auto const &m:map[q])
                {
                    degree[m]--;//与m相连接的节点被删除，m的度减1
                    if (degree[m]==1)//满足是下一个被删除节点的条件
                    {
                        Q.push(m);
                    }
                    
                }
                
            }
            

        }
        vector<int> ans;
        while (!Q.empty())
        {
            ans.push_back(Q.front());
            Q.pop();
        }
        
        return ans;
    }

};
// @lc code=end
//逻辑是对的，但是超时了
/*
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1)
        {
            return {0};
        }
        
        queue<vector<int>> q;
        int depth=0;
        int min=n;
        vector<int> ans;
        vector<int> used(edges.size(),0);
        vector<int> usedint(n,0);//标志哪个节点已经在树中
        bool flag=false;
        for (int i = 0; i < n; i++)
        {
            depth=0;
            used=vector<int>(edges.size(),0);
            usedint=vector<int>(n,0);
            usedint[i]=1;
            flag=false;
            for (int j = 0; j < edges.size(); j++)
            {
                if (edges[j][0]==i || edges[j][1]==i)   
                {
                    q.push(edges[j]);
                    used[j]=1;
                }
                
            }
            q.push({0,0});//标志位
            depth+=1;//根节点占一层
            while (!q.empty())
            {
                vector<int> a=q.front();
                q.pop();
                if (a[0]==0 && a[1]==0)
                {
                    depth++;
                   
                    if (depth>min)
                    {
                        flag=true;
                        q=queue<vector<int>>();//清空对列
                        break;
                    }
                    
                    if (q.empty())
                    {
                        break;
                    }
                    q.push({0,0});
                    continue;
                }
                int child=usedint[a[0]]==1?a[1]:a[0];//如果a[0]已经使用那说明a[1]才是子节点
                usedint[child]=1;
                pushq(child,edges,used,q);
            }
            
            if (flag)
            {
                continue;
            }
            
            if (depth==min)
            {
                ans.push_back(i);
            }
            if (depth<min)
            {
                min=depth;
                ans.clear();
                ans.push_back(i);
            }
            
          
            
        }
        return ans;
        
    }
    void pushq(int target,vector<vector<int>>& edges,vector<int>& used,queue<vector<int>>& q)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            if (used[i]==1)
            {
                continue;
            }
            if (edges[i][0]==target || edges[i][1]==target)
            {
                used[i]=1;
                q.push(edges[i]);
            }
            
            
        }
        
    }

*/