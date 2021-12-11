
struct ListNode {
       int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(nullptr) {
        }
};
#include<vector>
#include<algorithm>
using std::vector;
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        auto node=head;
        vector<int> ans;
        while (node!=nullptr)
        {
            //reserve_stack.emplace(node->val);
            ans.push_back(node->val);
            node=node->next;
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
       
        
    }
};