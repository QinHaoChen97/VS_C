#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> left, right(A.size());
        int mul = 1;
        left.push_back(1);

        for (int i = 0; i < A.size(); i++)
        {
            mul *= A[i];
            left.push_back(mul);
        }
        mul = 1;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            mul *= A[i];
            right[i]=mul;
        }
        right.push_back(1);
        vector<int> ans;
        for (int i = 0; i < A.size(); i++)
        {
            mul = left[i - 0] * right[i + 1];

            ans.push_back(mul);
        }
        return ans;
    }
};