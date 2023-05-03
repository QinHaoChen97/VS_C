#include<vector>
#include  <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n=n;
        vector<int> path;
        vector<vector<int>> ans;
        int sum=0;
        backtracking(1,k,path,ans,sum);
        return ans;
    }
    void backtracking(int start,const int&k,vector<int>& path,vector<vector<int>>& ans,int& num)
    //num用于减少重复计算
    {
        
        if(path.size()==k)
        {
            if(num==n)
            {
                ans.push_back(path);
            }
            return;
        }
        
        
        for(int i=start;i<10;i++)
        {   
            path.push_back(i);
            num+=i;
            if(num>n) //因为是递增序列，所以后面的元素也不需要再加入了
            {
                num-=i;
                path.pop_back();
                return;
            }
            backtracking(i+1,k,path,ans,num);
            num-=i;
            path.pop_back();
        }
        
    }
};