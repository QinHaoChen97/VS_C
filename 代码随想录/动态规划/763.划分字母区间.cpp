/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> vec(26,0);
        for (int i = 0; i < s.size(); i++)
        {
            vec[s[i]-'a']=i;
        }
        int end=vec[s[0]-'a'];
        int start=0;
        while (end<s.size())
        {          
            for (int i = start+1; i < end; i++)
            {
                end=max(vec[s[i]-'a'],end);
            }
            ans.emplace_back(end-start+1);
            if(end==s.size()-1)
            {
                break;
            }
            start=end+1;
            end=vec[s[start]-'a'];
        }
        return ans;
    }
};
// @lc code=end

