//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=23262&ru=/practice/8c82a5b80378478f9484d87d1c5f12a4&qru=/ta/coding-interviews/question-ranking
//利用递推公式dp[n]=dp[n-1]+dp[n-2]+...+dp[1]+dp[0]
//注意dp[0]需要初始化为1，代表从0台阶一步跳到n
//上式可以化简为dp[n]=2*dp[n-1]，当n>=2时
//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=23262&ru=/practice/8c82a5b80378478f9484d87d1c5f12a4&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int jumpFloorII(int number) {
        if (number==0)
        {
            return 1;
        }
        if (number==1)
        {
            return 1;
        }

        int dp=1;
        number=number-1;
        while (number)
        {
            number--;
            dp<<=1; //左移
        }
        return dp;
        
        
        
    }
};