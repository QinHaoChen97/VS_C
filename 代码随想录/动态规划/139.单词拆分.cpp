/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int sLen = s.size();
        vector<bool> dp(sLen + 1, false); // dp[j]代表当前字符能否由背包中的单词来表示
        dp[0] = true;
        sort(wordDict.begin(), wordDict.end(), [](const string &s1, const string &s2)
             { return s1.size() < s2.size(); });
        for (int j = wordDict[0].size(); j < sLen + 1; j++) //保证j大于单词的最小长度
        {
            for (int i = 0; i < wordDict.size(); i++)
            {
                if (wordDict[i].size() > j)
                {
                    break;
                }
                else
                {
                    if(dp[j-wordDict[i].size()]==false)
                    {
                        continue;
                    }
                    if(istrue(s,j-wordDict[i].size(),j-1,wordDict[i],0,wordDict[i].size()-1))
                    {
                        dp[j]=true;
                    }
                }
            }
        }
        return dp[sLen];
    }
    bool istrue(const string& s1,int s1Start,int s1End,const string& s2,int s2Start,int s2End)
    {
        while (s1Start<=s1End)
        {
            if(s1[s1Start++]!=s2[s2Start++])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
