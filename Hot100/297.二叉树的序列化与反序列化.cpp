/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/*
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/ 
#include<vector>
#include<string>
#include<list>
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        dfs_serialize_tree(root,str);
        return  str;
    }

    //递归序列化
    void dfs_serialize_tree(TreeNode* node,string &str)
    {
        if (node==nullptr)
        {
            str+="None,";
            return;
        }
        else
        {
            str+=to_string(node->val)+",";
            dfs_serialize_tree(node->left,str);
            dfs_serialize_tree(node->right,str);
            return;
        }
        
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> tree_list;
        string str;
        for (const auto &s : data)
        {
            if (s==',')
            {
                tree_list.push_back(str);
                str.clear();
            }
            else
            {
                str.push_back(s);
            }
        }
        return dfs_deserialize_tree(tree_list);
        
    }

    TreeNode* dfs_deserialize_tree(list<string> &tree_list)
    {
        /*
        if (tree_list.empty()) //不用判断非空，因为序列化是刚好的
            {
                return nullptr;
            }
        */
        
        string str=tree_list.front();
        tree_list.pop_front();
        if (str=="None")
        {
            return nullptr;
        }
        TreeNode* current_node=new TreeNode(stoi(str));
        current_node->left=dfs_deserialize_tree(tree_list);
        current_node->right=dfs_deserialize_tree(tree_list);
        return current_node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

