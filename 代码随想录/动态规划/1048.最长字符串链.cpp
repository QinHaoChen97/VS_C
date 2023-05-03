/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),[](const string& a, const string& b){return a.size() < b.size();});
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPredecessor(words[j],words[i]))
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    bool isPredecessor(const string& a, const string& b)
    {
        if (a.size() + 1 != b.size())
        {
            return false;
        }
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i == a.size();
    }
};
// @lc code=end

