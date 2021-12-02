/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Union //因为题解的
{
private:
    vector<int> parent;
    vector<double> weight;

public:
    //构造函数
    Union(int n)
    {
        parent.resize(n);
        weight.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            weight[i] = 1.0;
        }
    }

    void unionfun(int x, int y, double value)
    {
        int root_x = findp(x);
        int root_y = findp(y);
        if (root_x == root_y) //两者的根节点一样，不需要合并
        {
            return;
        }

        //合并根节点
        parent[root_x] = root_y;                        // 让x的根节点指向y的根节点，这样会产生一条新路径
        weight[root_x] = value * weight[y] / weight[x]; // 计算新路径的值
    }

    int findp(int id)
    {
        if (parent[id] == id) //如果一个人的根节点是自己
        {
            return parent[id];
        }
        int root = findp(parent[id]); //递归找到根节点
        weight[id] = weight[parent[id]] * weight[id];
        parent[id] = root;
        return parent[id];
    }

    double isconnected(int x, int y)
    {
        int root_x = findp(x);
        int root_y = findp(y);
        if (root_x == root_y) // 属于同一个集合中，x和y可以算出倍数关系
        {
            return weight[x] / weight[y];
        }
        else
        {
            return -1.0;
        }
    }
};

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, int> m;
        int id = 0;
        Union u(2 * equations.size());
        for (int i = 0; i < equations.size(); i++)
        {
            if (m.find(equations[i][0]) == m.end())
            {
                m[equations[i][0]] = id++;
            }
            if (m.find(equations[i][1]) == m.end())
            {
                m[equations[i][1]] = id++;
            }

            u.unionfun(m[equations[i][0]], m[equations[i][1]], values[i]); //合并集，合并操作里面包含路径压缩
        }

        vector<double> ans;
        // 查询
        for (int i = 0; i < queries.size(); i++)
        {
            string var0 = queries[i][0];
            string var1 = queries[i][1];
            if (m.find(var0) == m.end() || m.find(var1) == m.end()) // 该字母存在于equations中
            {
                ans.push_back(-1.0);
            }
            else
            {
                ans.push_back(u.isconnected(m[var0], m[var1]));
            }
        }
        return ans;
    }
};


// @lc code=end
