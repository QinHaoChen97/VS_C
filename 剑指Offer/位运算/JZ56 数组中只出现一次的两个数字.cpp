#include  <bits/stdc++.h>
using namespace std;
//https://www.nowcoder.com/practice/389fc1c3d3be4479a154f63f495abff8?tpId=13&tqId=1375231&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//比下面写的更简便的方法，根据异或结果分组，每组组内再异或便可以得到答案
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int array_len=array.size();
        sort(array.begin(),array.end());
        int count=0; //记录找到的个数
        vector<int> ans;
        int i=0;
        while (i<array_len)
        {
            if ((i+1)>=array_len)  //说明只剩一个数，就是最后的答案
            {
                ans.push_back(array[i]);
                break;
            }
            else if (!(array[i]^array[i+1]))  //两个数相等，都不是答案
            {
                i+=2;
            }
            else //找到一个答案
            {
                ans.push_back(array[i]);
                count++;
                if (count==2)
                {
                    break;
                }
                else
                {
                    i++;
                }
                
                
            }
        }
        return ans; //没有意义，防止编译错误
        

    }
};