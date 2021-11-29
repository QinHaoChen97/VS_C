// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using std::vector;
using std::string;
using std::unordered_map;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> count;
        unordered_map<char,int> used;
        for (const auto &i : p)
        {
            count[i]++;
            used[i]=0;
        }
        int left=0,right=0; //滑动窗口
        int s_length=s.size(),p_length=p.size();
        while (left<=right && right<s_length && s_length-left>=p_length)
        {
            if (used.find(s[right])!=used.end()) //存在该字符
            {
                if (used[s[right]]!=count[s[right]]) //还未添加过该字符
                {
                    used[s[right]]++;
                    
                }
                else//添加过，移动左边界直到删除重复的字符，同时将其中被删除的元素置false
                {
                    while (s[left]!=s[right])
                    {
                        used[s[left]]--;
                        left++;
                    }
                    //退出while循环，此时找到重复的字符了
                    left++;
                    
                } 
            }
            else
            {
                //不存在该字符
                for (auto start=used.begin();start!=used.end();start++)
                {
                    (*start).second=0;
                }
                left=right+1;
                
            }
            right++; //右窗口先移动到下一个要浏览的字符
            //判断当前的窗口中的元素是不是异位词
            if (right-left==p_length)
            {
                ans.push_back(left);
            }
            
            
        }
        return ans;
    }
};
// @lc code=end

