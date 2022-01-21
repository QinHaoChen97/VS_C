//https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=23291&ru=/practice/9f3231a991af4f55b95579b44b7a01ba&qru=/ta/coding-interviews/question-ranking
/*
描述
输入一个长度为 n 字符串，打印出该字符串中字符的所有排列，你可以以任意顺序返回这个字符串数组。
例如输入字符串ABC,则输出由字符A,B,C所能排列出来的所有字符串ABC,ACB,BAC,BCA,CBA和CAB。
*/

//下面的答案是o(n^n)的复杂度，纯暴力算法
//https://blog.nowcoder.net/n/56a75d796fbb475da047efda543299b9
//这里可以利用全排列得到o(n!)的算法复杂度
//里面的str传递可以改为引用传递，更省内存
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    string s;
    vector<bool> used;
    unordered_set<string> ans; //用于排除重复答案
public:
    vector<string> Permutation(string str) {
        int str_len=str.size();
        if (str_len==0)
        {
            return {};
        }
        s=str;
        used=vector(str_len,false);
        string sub_ans="";
        backtracking(sub_ans,str_len);
        return vector<string>(ans.begin(),ans.end());
    }
    void backtracking(string& sub_ans,const int& len)
    {
        if (sub_ans.size()==len)
        {
            ans.insert(sub_ans);
            return;
        }
        for (int i = 0; i < len; i++)
        {
            if (used[i]==false)
            {
                used[i]=true;       //递归
                sub_ans+=s[i];
                backtracking(sub_ans,len);
                sub_ans.pop_back(); //回溯
                used[i]=false;
            }
            
        }
    }
};