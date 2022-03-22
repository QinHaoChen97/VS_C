//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=23255&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 1;
        }
        int first=1,second=1;
        n=n-2;
        int ans;
        while (n)
        {
            n--;
            ans=first+second;
            first=second;
            second=ans;
        }
        return ans;
        
    }
};