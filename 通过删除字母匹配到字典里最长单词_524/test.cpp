/*
给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。
示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"

示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    static auto cmp(string a,string b)  //这里要将其指定为静态函数，因为静态函数没有this指针，或者将函数写在类外面作为全局函数也可以。
    {
        if (a.size()==b.size())
        {       
            return a<b;
        }
        return a.size()>b.size();
    };
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        int s_size=s.size();
        int s_left=0,dict_str_left=0;//指向字符串首的指针
        for(auto & str:dictionary)
        {   
            int str_size=str.size();    
            //排除特殊情况
            if (s_size<str_size)
            {
                continue;
            }
            if (s_size==str_size)
            {
                if (s==str)
                {
                    return str;
                }
            }
            //利用双指针对两字符串比较
            while (dict_str_left < str_size && s_left < s_size)
            {
                if (s[s_left]==str[dict_str_left])
                {
                    s_left++;
                    dict_str_left++;
                }
                else
                {
                    s_left++;
                }
            }
            //退出while循环
            if (dict_str_left==str_size) //说明完成了一次匹配
            {
                return str;
            }
            else//否则将指针置零进入下一个字符串匹配
            {
                dict_str_left=0;
                s_left=0;
            }
            
            
        }
        return "";
    }
};
int main()
{
    
}