//https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=23273&ru=/practice/9023a0c988684a53960365b889ceaf5e&qru=/ta/coding-interviews/question-ranking
//参考题解
//https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=23273&ru=/practice/9023a0c988684a53960365b889ceaf5e&qru=/ta/coding-interviews/question-ranking
class Solution
{
public:
    int NumberOf1(int n)
    {
        int ans = 0;
        int mark = 0x01; //之所以要设置这个mark是因为如果是右移n，对于负数来说高位可能是补1而不是补0
        while (mark != 0)
        {
            if (mark & n)
                ++ans;
            mark <<= 1;
        }
        return ans;
    }
};

//利用n&(n-1)的特性更为方便
//该方法可以每次消去当前数右边最小的那个1
