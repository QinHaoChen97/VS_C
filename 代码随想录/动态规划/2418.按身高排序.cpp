/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 *
 * [2418] 按身高排序
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> pos(names.size());
        for (int i = 0; i < names.size(); i++)
        {
            pos[i]=i;
        }
        sort(pos.begin(),pos.end(),[=](int a,int b)->bool{
            if(heights[a]>heights[b])
            {
                return true;
            }
            else
            {
                return false;
            }
        });
        vector<string> ans(names.size());
        for (int i = 0; i < names.size(); i++)
        {
            ans[i] = names[pos[i]];
        }
        return ans;
    }
};
// @lc code=end

