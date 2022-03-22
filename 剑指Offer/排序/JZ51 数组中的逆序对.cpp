
//这应该是困难题
//参考本题解，使用归并排序后，再将左右两边做逆序对统计
//https://blog.nowcoder.net/n/a86e570ff27c4b1badfe517e18721d16
#include  <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> sort_data;
    int count;
public:
    int InversePairs(vector<int> data) {
        int data_len=data.size();
        sort_data.resize(data_len);
        count=0;
        MergeSort(0,data_len-1,data);
        return count;
    }
    
    void MergeSort(int left,int right,vector<int>& data)
    {
        if (left>=right)
        {
            return;
        }
        int mid=left+(right-left)/2;
        MergeSort(left,mid,data);
        MergeSort(mid+1,right,data);
        Merge(left,mid,mid+1,right,data);
        
    }
    
    void Merge(int l_left,int l_right,int r_left,int r_right,vector<int>& data)
    {
        int cur=l_left;
        int start=l_left,end=r_right;
        while (l_left<=l_right && r_left<=r_right)
        {
            if (data[r_left]<data[l_left])
            {
                sort_data[cur++]=data[r_left++];
                count=(count+l_right-l_left+1)%1000000007; //逆序对个数
            }
            else
            {
                sort_data[cur++]=data[l_left++];
            }
        }
        //插入剩余的未合并字段
        while (l_left<=l_right)
        {
            sort_data[cur++]=data[l_left++];
        }
        while (r_left<=r_right)
        {
            sort_data[cur++]=data[r_left++];
        }
        //拷贝回原来的数组
        while (start<=end)
        {
            data[start]=sort_data[start];
            start++;
        }
    }
    
};