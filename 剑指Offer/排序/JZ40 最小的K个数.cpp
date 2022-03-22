// https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=23263&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <bits/stdc++.h>
using namespace std;
//不可以直接使用堆排，因为堆排只能保证最高点为最小的值，不能保证前四个位置就是最小值
// class Solution
// {
// public:
//     vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
//     {
//         vector<int> heap;
//         auto input_size = input.size();
//         if (k >= input_size)
//         {
//             return input;
//         }
//         heap.push_back(input[0]);
//         heap_size++;
//         for (int i = 1; i < input_size; i++)
//         {
//             heap.push_back(input[i]);
//             heap_size++;
//             sort_heap(heap,i);
//         }
//         return vector<int>(heap.begin(),heap.begin()+k);
//     }
//     void sort_heap(vector<int> &heap, int pos)
//     {
//         while (pos > 0)
//         {
//             int pre = (pos - 1) / 2;
//             int l_son = pre * 2 + 1;
//             if (l_son+1 < heap_size) //是否有右子树
//             {
//                 int min_son = heap[l_son] > heap[l_son + 1] ? l_son+1 : l_son;
//                 if (heap[min_son] < heap[pre]) //生成最小堆
//                 {
//                     swap(heap[min_son], heap[pre]);
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             else //只有左子树
//             {
//                 if (heap[l_son]<heap[pre])
//                 {
//                     swap(heap[pre], heap[l_son]);
//                 }
//                 else
//                 {
//                     break;
//                 }
                
//             }

//             //更新序号
//             pos = (pos - 1) / 2;
//         }
//     }

// private:
//     int heap_size;
// };

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int input_size=input.size();
        if(k>=input_size)
        {
            return input;
        }
        else{
            sort(input.begin(),input.end());
            return vector<int>(input.begin(),input.begin()+k);
        }
    }
};