//https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=23287&ru=/practice/d77d11405cc7470d82554cb392585106&qru=/ta/coding-interviews/question-ranking
//这题有其他解法，比如利用库函数stringstream https://blog.nowcoder.net/n/dcf69c062c884b5a870828233a6cbfef
#include<string>
using std::string;
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty())
        {
            return str;
        }
        string ans="";
        int str_len=str.size();
        int start=0,end=0;
        for (int i = 0; i < str_len; i++)
        {
            if (str[i]!=' ')
            {
                end++;
            }
            else
            {
                ans=str.substr(start,end-start)+" "+ans;
                start=i+1;
                end=i+1;
            }
        }
        ans=str.substr(start)+" "+ans;
        ans.pop_back(); //弹出末尾多余的空格
        return ans;
                
    }
};