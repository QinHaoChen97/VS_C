#include<string>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int findNthDigit(int n) {
        int count=-1;
        int number=0;
        while (true)
        {
            int current_times=count+count_len(number);
            if (current_times==n)
            {
                return number%10;
            }
            else if (current_times<n)
            {
                count=current_times;
                number++;
            }
            else
            {
                break;
            }
        }
        //当前的数字长度过长
        int diff=n-count;
        return to_string(number)[diff-1]-'0';
        
    }
    int count_len(int num)  //位数的复杂度要用分区间法,但是这种写法复杂度还是太大，时间上通不过
    {
        if(num<10)
        {
            return 1;
        }
        else
        {
            int base=10;
            int count=1;
            while (num>base)
            {
                count++;
                base*=10;
            }
            return count;
        }
        
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int findNthDigit(int n) {
        // write code here
        if(n < 10)
            return n;
        int start = 1;
        int end = 10;
        long long bit = 1;
        //找到对应的区间
        while((long long)n >= (end - start)*bit){   //通过分区间法直接定位n是在哪一个区间，这里的longlong令人费解
            //减去之前的位数
            n =  n - (end - start)*bit;
            //区间头
            start *= 10;
            //区间尾
            end *= 10;
             
            //位数++
            ++bit;
             
        }
        //找到当前数
        string res = to_string(start + (n-1)/bit); //注意这里是n减1
       //返回对应的数字
        return res[(n-1)%bit] - '0';
    }
};