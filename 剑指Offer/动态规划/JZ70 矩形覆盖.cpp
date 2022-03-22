//https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=23283&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

//https://blog.nowcoder.net/n/74aadc6d1b264dd3ade8b827f2809a5d
class Solution {
public:
    int rectCover(int number) {
        //dp[n]由dp[n-1]和dp[n-2]决定
        if (number==0)
        {
            return 0;
        }
        
        if (number==1)
        {
            return 1;
        }
        if (number==2)
        {
            return 2;
        }

        //初始化
        int dpn_1=1;
        int dpn_2=2;
        number=number-2;
        int ans=0;
        while (number)
        {
            ans=dpn_1+dpn_2;
            dpn_1=dpn_2;
            dpn_2=ans;
            number--;
        }
        return ans;
        
        
        
    }
};