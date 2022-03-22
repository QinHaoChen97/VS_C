#include <vector>
using std::vector;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int> &array)
    {
        // write code here
        int array_len = array.size();
        if (array_len == 0)
        {
            return {};
        }
        vector<int> ans;
        vector<int> sub_arr;
        int max = array[0];
        int sum = array[0];
        ans.push_back(array[0]);
        sub_arr.push_back(array[0]);
        for (int i = 1; i < array_len; i++)
        {
            if (sum < 0)
            {
                sub_arr.clear();
                sum = array[i];
            }
            else
            {
                sum += array[i];
            }

            sub_arr.push_back(array[i]);
            if (sum > max)
            {
                ans = sub_arr;
                max = sum;
            }
            else if (sum == max)
            {
                if (ans.size() <= sub_arr.size())
                {
                    ans = sub_arr;
                }
            }
        }
        return ans;
    }
};