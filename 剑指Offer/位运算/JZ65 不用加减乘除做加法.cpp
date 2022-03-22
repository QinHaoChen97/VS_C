//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=23249&ru=/practice/59ac416b4b944300b617d4f7f111b215&qru=/ta/coding-interviews/question-ranking
//题解
//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=23249&ru=/practice/59ac416b4b944300b617d4f7f111b215&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int Add(int num1, int num2) {
        while(num2!=0)
        {
            int num1=num1^num2;  //第一次是计算不含进位的值,之后是把进位不断累加直到没有进位
            int tmp=(unsigned int)(num1&num2)<<1;// 进位
            num2=tmp;
        }
        return num1;
    }
};