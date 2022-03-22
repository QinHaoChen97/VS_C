// https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=23457&ru=/practice/d9820119321945f588ed6a26f0a6991f&qru=/ta/coding-interviews/question-ranking
// https://blog.csdn.net/Fizz6018/article/details/107043508
//参考题解，使用大根堆和小根堆来解决
//或者利用插入排序算法也可以
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    priority_queue<int> min_deap;                            //大顶堆，堆顶为最小元素
    priority_queue<int, vector<int>, greater<int>> max_deap; //小顶堆，堆顶为最大元素
public:
    void Insert(int num)
    {
        min_deap.push(num),
            max_deap.push(min_deap.top());
        min_deap.pop();
        if (min_deap.size() < max_deap.size()) //小顶堆的个数应当小于或等于大顶堆(相差最多为1)
        {
            min_deap.push(max_deap.top());
            max_deap.pop();
        }
    }

    double GetMedian()
    {
        return min_deap.size() > max_deap.size() ? static_cast<double>(min_deap.top()) : static_cast<double>((min_deap.top() + max_deap.top()) / 2.0);
    }
};
