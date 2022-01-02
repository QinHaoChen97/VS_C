// https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=23289&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
/*
输入： [4,8,6,12,16,14,10]
返回值：true
*/
#include <vector>
using std::vector;
class Solution  //这个会超时，但逻辑是对的
{
private:
    vector<int> se;

public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        //方法一 分而治之
        se = sequence;
        int se_len = se.size();
        if (se_len == 0)
        {
            return false; //默认空树不为二叉搜索树
        }
        else if (se_len <= 2)
        {
            return true; //退化情况
        }
        else
        {
            return judge(0, se_len-1); //左闭右闭区间
        }
    }
    bool judge(int start, int end)
    {
        if (end - start+1 <= 2) //长度小于等于2，必定可以组成一颗二叉搜索树子树
        {
            return true;
        }
        int root_val = se[end];
        int left_end = end - 1;         //记录左子树的结尾
        while (se[left_end] > root_val && left_end>=0 ) //节点值不相同，这里用>即可
        {
            left_end--;
        }
        // left_end此时指向左子树的尾部
        for (int i = left_end - 1; i >= 0; i--)
        {
            if (se[i]>root_val)
            {
                return false;
            }
            
        }
        return judge(0,left_end) && judge(left_end+1,end-1); //左闭右开
    }
};
#include<stack>
#include<limits.h>
using std::stack;
class Solution {
public:
    bool VerifySquenceOfBST1(vector<int> sequence) {
        if (sequence.empty())
        {
            return false;
        }
        stack<int> sta;
        int root=INT_MAX; //假设最靠右的那个节点为
        int sequence_len=sequence.size();
        for (int i = sequence_len-1; i >=0; i--)
        {
            int val=sequence[i];
            if (val>root) //寻找的是当前节点的父节点或左子树，如果sequence[i]>root，则不满足条件
            {
                return false;
            }
            else
            {
                while (!sta.empty() && sta.top()>val) //弹出右兄弟和根节点（最后一个弹出）
                {
                    root=sta.top();
                    sta.pop();
                }
                sta.push(val);
                
            }
            
            
        }
        return true;
        
    }
};