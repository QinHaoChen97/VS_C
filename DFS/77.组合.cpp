// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
//https://leetcode-cn.com/problems/combinations/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n,k,path,1);
        return ans;
    }
    void dfs(const int &n,const int &k,vector<int> &path,int startindex)
    {
        int path_size=path.size();
        if (path_size==k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startindex;(k-path_size<=n-i+1); i++)//(k-path_size>=n-i+1) 剪枝
        //若剩下的数不足以和path凑成有k个数的组合，则不进行递归
        {
            path.push_back(i);
            dfs(n,k,path,i+1);
            path.pop_back();
        }
    }
};
// @lc code=end
//模板
/*
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}




作者：carlsun-2
链接：https://leetcode-cn.com/problems/combinations/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-0uql/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*
/