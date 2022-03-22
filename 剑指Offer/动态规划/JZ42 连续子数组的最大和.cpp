//https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=23259&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <vector>
using namespace std;
class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int array_len = array.size();
        if (array_len == 0)
        {
            return -1;
        }
        int max = array[0];
        int sum=array[0];
        for (int i = 1; i < array_len; i++)
        {
            if (sum<0)
            {
                sum=array[i];
            }
            else
            {
                sum+=array[i];
            }
            if (max<sum)
            {
                max=sum;
            }
            
            
            
            
        }
        return max;
    }
};