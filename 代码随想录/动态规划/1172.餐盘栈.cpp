/*
 * @lc app=leetcode.cn id=1172 lang=cpp
 *
 * [1172] 餐盘栈
 */

// @lc code=start
#include<vector>
#include<stack>
#include<set>
using namespace std;
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        sta_vec.clear();
        s_not_full.clear();
        sta_vec.push_back(stack<int>());
        s_not_full.insert(0);
        s_not_null.clear();
    }
    
    void push(int val) {
        if(s_not_full.size() != 0)
        {
            // get the last element of set
            int index = *(s_not_full.begin());
            sta_vec[index].push(val);
            if(sta_vec[index].size()==1)  //新增加的元素，原来是空的，现在不是空的了
            {
                s_not_null.insert(index);
            }
            if(sta_vec[index].size() == capacity && s_not_full.find(index) != s_not_full.end())
            {
                s_not_full.erase(index);
            }
            return;
        }
        else
        {
            sta_vec.push_back(stack<int>());
            sta_vec[sta_vec.size()-1].push(val);
            if(capacity != 1)
            {
                s_not_full.insert(sta_vec.size()-1);
            }
            s_not_null.insert(sta_vec.size()-1);
            return;
        }
    }
    
    int pop() {
        if (s_not_null.size()!=0)
        {
            int index = *(s_not_null.rbegin());
            if(sta_vec[index].size() == 1)
            {
                s_not_null.erase(index);
            }
            if (sta_vec[index].size() == capacity)
            {
                s_not_full.insert(index);
            }
            int tmp = sta_vec[index].top();
            sta_vec[index].pop();
            return tmp;
        }
        else
        {
            return -1;
        }
    }
    
    int popAtStack(int index) {
        if (s_not_null.find(index) != s_not_null.end())
        {
            if(sta_vec[index].size() == 1)
            {
                s_not_null.erase(index);
            }
            if (sta_vec[index].size() == capacity)
            {
                s_not_full.insert(index);
            }
            int tmp = sta_vec[index].top();
            sta_vec[index].pop();
            return tmp;
        }
        else
        {
            return -1;
        }
        
    }
private:
    int capacity;
    vector<stack<int>> sta_vec;
    set<int> s_not_full;
    set<int> s_not_null;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end

