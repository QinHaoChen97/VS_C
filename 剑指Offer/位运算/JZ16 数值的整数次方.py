# https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=23277&ru=/practice/8ee967e43c2c4ec193b040ea7fbb10b8&qru=/ta/coding-interviews/question-ranking
# 实现函数 double Power(double base, int exponent)，求base的exponent次方。
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param base double浮点型
# @param exponent int整型
# @return double浮点型
#
class Solution:
    def Power(self, base: float, exponent: int) -> float:
        pos=True
        if base<0: #判断正负
            pos=False
            base=-base
        if base == 0:
            return 0
        if base == 1:
            return 1
        reverse=False
        if exponent == 0:
            return 1
        elif exponent < 0:
            reverse = True  # 是负数的话最后需要取倒数
            exponent = -exponent
        # 将exponent不断的对半拆分计算
        ans=1
        while(True):
            return_dict=self.Sub_Power(base, exponent)
            ans=ans*return_dict[0]
            if return_dict[1] == 0:
                break
            else:
                exponent=return_dict[1]
        
        #正负还有是否需要倒置
        if not pos:
            ans=-ans
        if reverse:
            ans=1/ans
        return ans

    def Sub_Power(self, base: float, exponent: int) -> list:
        n = 1
        while True:
            if n*2 <= exponent:
                base = base*base
                n = n*2
            else:
                break
        return [base,exponent-n]

'''
利用位运算
https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=23277&ru=/practice/8ee967e43c2c4ec193b040ea7fbb10b8&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
 
    double Power(double b, int n) {
        if (n < 0) {
            b = 1 / b;
            n = -n;
        }
        double x = b; // 记录x^0, x^1, x^2 ...
        double ret = 1.0;
        while (n) {
            if (n&1) {
                ret *= x; // 二进制位数是1的，乘进答案。
            }
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};
上述方法相当于遍历n的二进制位，是1就乘进结果
时间复杂度：O(logn)，因为n的二进制位个数为logn
空间复杂度：O(1)
'''