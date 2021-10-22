// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem882.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define pii pair<int, int>

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<pii>> graph(N);
        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        map<int, int> dist;//从0到达当前点走了几步
        dist[0] = 0;
        for (int i = 1; i < N; ++i)
            dist[i] = M+1;

        map<pii, int> used;
        int ans = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node]) continue;//如果到达当前节点需要的步数比其他路径的多，那
            //就没必要将其加入队列中了，因为剩余步数比别人少，从当前节点出去走的路径肯定也比
            //别人少
            dist[node] = d;

            // Each node is only visited once.  We've reached
            // a node in our original graph.
            ans++;

            for (auto pair: graph[node]) {
                // M - d is how much further we can walk from this node;
                // weight is how many new nodes there are on this edge.
                // v is the maximum utilization of this edge.
                int nei = pair.first;//当前点与nei
                int weight = pair.second;//的距离
                used[{node, nei}] = min(weight, M - d);//利用率

                // d2 is the total distance to reach 'nei' (nei***or) node
                // in the original graph.
                int d2 = d + weight + 1;
                if (d2 < min(dist[nei], M+1)) {//需要到达nei点的时候
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }
/*
             if (d2 < min(dist[nei], M+1)) {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
直接写成if(d2<dist[nei])就可以了

dist[nei]表示当前路径到达dist[nei]的最小步数，如果新的路径到达nei节点的所需的步数d2大于dist[nei]，那就没有必要将其压入队列，因为此时剩余能走的步数少，在nei节点之后所有能走的路径已经被剩余步数更多的情况包含了（这相当于是做了一个剪枝）。
*/
        // At the end, each edge (u, v, w) can be used with a maximum
        // of w new nodes: a max of used[u, v] nodes from one side,
        // and used[v, u] nodes from the other.
        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            ans += min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};
// @lc code=end

