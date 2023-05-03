/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>& vec1,const vector<int>& vec2)
        {
           return vec1[0]==vec2[0]?vec1[1]<vec2[1]:vec1[0]>vec2[0]; 
        });
        vector<vector<int>> ans;
        for (int i = 0; i < people.size(); i++)
        {
            int pos=people[i][1];
            ans.insert(ans.begin()+pos,people[i]);
        }
        return ans;
    }
};
// @lc code=end

