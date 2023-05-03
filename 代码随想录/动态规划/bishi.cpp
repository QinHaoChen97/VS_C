#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param edges int整型vector 
     * @return int整型
     */
    unordered_map<int,int> m;
    bool iscircle;
    int maxlen;
    void dfs(int start,int target,vector<bool>& used,int length)
    {
        if(used[target]==true)
        {
            if(target==start)
            {
                maxlen=max(maxlen,length);
            }
            return;
        }
        if(m.find(start)==m.end())
        {
            return;
        }
        used[target]=true;
        length++;
        dfs(start,m[target],used,length);
    }
    int longestCycle(vector<int>& edges) {
        // write code here
        
        for (int i = 0; i < edges.size(); i++)
        {
            if(edges[i]!=-1)
            {
                m[i]=edges[i];
            }
        }
        iscircle=false;
        maxlen=-1;
        vector<bool> used(edges.size(),false);
        for (int i = 0; i < edges.size(); i++)
        {
            used.resize(edges.size(),false);
            dfs(i,i,used,0);
        }
        return maxlen;
        
    }
};