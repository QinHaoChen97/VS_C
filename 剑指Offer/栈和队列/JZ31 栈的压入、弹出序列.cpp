// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=23290&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//这应该是一个随机栈问题
/*
示例2
输入：
[1,2,3,4,5],[4,3,5,1,2]
复制
返回值：
false
复制
说明：
由于是[1,2,3,4,5]的压入顺序，[4,3,5,1,2]的弹出顺序，要求4，3，5必须在1，2前压入，且1，2不能弹出，但是这样压入的顺序，1又不能在2之前弹出，所以无法形成的，返回false
*/
#include <vector>
#include <stack>
using std::stack;
using std::vector;
class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        //我们直接用随机栈的过程来模拟能不能产生当前的栈
        stack<int> sta;
        vector<int> ans;
        int popV_len = popV.size();
        int have_push = -1; //已经推入到栈中的值的位置
        for (int i = 0; i < popV_len; i++)
        {
            int pop_value = popV[i];
            if (!sta.empty() && pop_value == sta.top())  //弹出元素与栈顶元素一致，直接弹出即可
            {
                sta.pop();
                continue;
            }

            for (have_push++; have_push < popV_len && pushV[have_push] != pop_value; have_push++) //不一致，则一直压入直到出现压入节点或者找不到压入节点
            {
                sta.push(pushV[have_push]);
            }
            // pushV[have_push]==pop_value  或者 pushV中没有该元素，如果是前者，无需再做任何操作，因为此时pushV[have_push]压入后立马就会弹出
            if (have_push == popV_len) //没有该元素
            {
                return false;
            }
        }

        return true;
    }
};