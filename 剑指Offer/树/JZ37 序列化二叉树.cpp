#include<queue>
#include<string>
#include<string.h>
#include<vector>
using std::queue;
using std::string;
using std::vector;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        queue<TreeNode*> q;
        string s="";
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if (node==nullptr)
            {
                s+="#";
                continue;
            }
            
            s+=std::to_string(node->val);
            s+=',';
            q.push(node->left);
            q.push(node->right);
            
        }
        char* ans=new char[s.length()];
        strcpy(ans,s.c_str());
        return ans;
    }
    TreeNode* Deserialize(char *str) {
        vector<TreeNode*> serialize_vec=split(str);;  
        
        int stserialize_vec_len=serialize_vec.size();
        TreeNode* root=serialize_vec[0];
        int root_pos=0;
        int count=0;
        for (int i = 1; i < stserialize_vec_len; i++)
        {
            if (count==0)
            {
                root->left=serialize_vec[i];
            }
            else //count==1
            {
                root->right=serialize_vec[i];
            }
            
            
            count++;
            if (count==2)
            {
                count=0;
                for (root_pos = root_pos+1; root_pos < stserialize_vec_len; root_pos++) //调整当前对应的父节点的位置
                {
                    if (serialize_vec[root_pos]!=nullptr)
                    {
                        break;
                    }
                    
                }
                
            }
            root=serialize_vec[root_pos];
        }
        return serialize_vec[0];

    }
    vector<TreeNode*> split(const char * const str)
    {
        string s=str;
        int val;
        vector<TreeNode*> serialize_vec;
        for (auto ch : s)
        {
            if (ch==',') //找到一个val
            {
                serialize_vec.push_back(new TreeNode(val));
                val=0;
            }
            else if (ch=='#')
            {
                serialize_vec.push_back(nullptr);
            }
            else
            {
                //是数字
                val=val*10+(ch-'0');
            }
        }
        return serialize_vec;
    }
};