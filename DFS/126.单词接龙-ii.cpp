// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem126.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> dict;//放置还未添加的图节点
        bool have_endword=false;
        for (const auto &w:wordList)
        {
            if (w==endWord)
            {
                have_endword=true;
            }
            dict.insert(w);
        }
        if (!have_endword)
        {
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> beginw_set{beginWord},endw_set{endWord};
        unordered_map<string,vector<string>> map;//构建一个图
        bool found=false,reserve=false;
        //----------------------------图构建--------------------------------
        while (!beginw_set.empty())
        {
            unordered_set<string> q;//暂存
            for(const auto &w:beginw_set)
            {
                string s=w;
                //每次更改一个字母
                for (int i = 0; i < s.size(); i++)
                {
                    char ch=s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i]='a'+j;
                        if (endw_set.count(s))
                        {
                            found=true;
                            reserve?map[s].push_back(w):map[w].push_back(s);
                        }
                        if (dict.count(s))
                        {
                            reserve?map[s].push_back(w):map[w].push_back(s);
                            q.insert(s);
                            //dict.erase(s);
                            //不可以在这里就擦除，因为beginword有可能不只有一个单词
                            //会建立从beginword到endowrd的多个通道
                        }
                    }
                    s[i]=ch;
                }
                
            }
            if (found)//这样可以保证构建的图中找到的能到达的序列一定是最短的
            {
                break;
            }
            for (const auto &w:q)//防止高层数（经过更多轮变化）的单词指向低层数的
            {
                if (dict.count(w))
                {
                    dict.erase(w);
                }
            }
            
            if (q.size()<=endw_set.size())
            {
                beginw_set=q;
            }
            else
            {
                beginw_set=endw_set;
                endw_set=q;
                reserve=!reserve;
            }
        }
        //--------------------------图构建--------------------------
        if (found)
        {
            vector<string> path{beginWord};
            backtracking(beginWord,endWord,ans,path,map);
        }
        
        return ans;
        
    }
    void backtracking(const string &beginword,const string &endword,
    vector<vector<string>> &ans,vector<string> &path,
    unordered_map<string,vector<string>> &map)//map不能加const，否则下面的for循环无法使用
    {
        if (beginword==endword)
        {
            ans.push_back(path);
            return;
        }
        for (const auto &w:map[beginword])
        {
            path.push_back(w);
            backtracking(w,endword,ans,path,map);
            path.pop_back();
        }
        
        
    }
};
// @lc code=end
/*
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    vector<vector<string>> ans;
    unordered_set<string> dict;
    for (const auto &w : wordList)
    {
        dict.insert(w);
    }
    if (!dict.count(endWord))
    {
        return ans;
    }
    dict.erase(beginWord);
    dict.erase(endWord);
    unordered_set<string> q1{beginWord}, q2{endWord};
    unordered_map<string, vector<string>> next;//构建一个图
    bool reversed = false, found = false;
    while (!q1.empty())
    {
        unordered_set<string> q;
        for (const auto &w : q1)
        {
            string s = w;
            for (size_t i = 0; i < s.size(); i++)
            {
                char ch = s[i];
                for (int j = 0; j < 26; j++)
                {
                    s[i] = j + 'a';
                    //----这两个判断条件是互斥的，因为dict.erase(beginWord);
                    //dict.erase(endWord);
                    if (q2.count(s))//找到要变化的数组了，endword==s
                    {
                        //如果现在是从endword往beginword进行搜索的话则需要将s(beginword)作为key
                        reversed ? next[s].push_back(w) : next[w].push_back(s);
                        found = true;
                    }
                    if (dict.count(s))//构建一个图
                    {
                        reversed ? next[s].push_back(w) : next[w].push_back(s);
                        q.insert(s);
                    }
                    //----
                }
                s[i] = ch;
            }
        }
        if (found)
        {
            break;
        }
        for (const auto &w : q)//防止相同层次之间的转换
        {
            dict.erase(w);
        }
        //--------选择个数较少的一端来构建图
        if (q.size() <= q2.size())
        {
            q1 = q;
        }
        else
        {
            reversed = !reversed;
            q1 = q2;//endword和beginword交换
            q2 = q;//endword等于构建图的外层
        }
        //-----------------------------------------------------------------
    }
    if (found)
    {
        vector<string> path = {beginWord};
        backtracking(beginWord, endWord, next, path, ans);
    }
    return ans;
}
// 辅函数
void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans)
{
    if (src == dst)
    {
        ans.push_back(path);
        return;
    }
    for (const auto &s : next[src])
    {
        path.push_back(s);
        backtracking(s, dst, next, path, ans);
        path.pop_back();
    }

*/