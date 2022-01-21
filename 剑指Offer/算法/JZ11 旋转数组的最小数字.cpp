// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=23269&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <vector>
using std::vector;
class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        //找到谷点
        int array_len = rotateArray.size();
        if (array_len == 1)
        {
            return rotateArray[0];
        }
        int flag=rotateArray[0];
        for (int i = 1; i < array_len; i++)
        {
            if (rotateArray[i]<flag)
            {
                return rotateArray[i];
            }
            
        }
        return flag;
        
    }
};
//https://blog.nowcoder.net/n/1e5cd58cbd0c4c3b855b635c1230469c
//二分算法这里卡住了，值得回味
class Solution1 {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int array_len = rotateArray.size();
        if (array_len == 1)
        {
            return rotateArray[0];
        }
        
        int left=0,right=array_len-1;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            if (rotateArray[mid]>rotateArray[right])  //是要和当前区间的最后一个元素来比较
            {
                left=mid+1;
            }
            else if(rotateArray[mid]<rotateArray[right])
            {
                right=mid;
            }
            else 
            //重点
            //两者相等，无法判断应该怎么缩减，那就逐步缩减区间,right--
            {
                right--;
            }
            
            
            
        }
        //left==right;
        return rotateArray[left];
        
    }
};