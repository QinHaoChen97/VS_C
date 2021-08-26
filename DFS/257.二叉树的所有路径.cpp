/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*leetcode会提供，不需要自己写
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    }
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root,path);
        string str;
        vector<string> ans_str;
        for (const auto &int_vector:ans)
        {
            str="";
            for (const auto & i:int_vector)
            {
                str+=to_string(i);
                str+="->";
            }
            str.pop_back();//删除队尾的->
            str.pop_back();
            ans_str.push_back(str);
        }
        return ans_str;
        
    }
    void dfs(TreeNode* node,vector<int> &path)
    {
        if (node==NULL)
        {   
            return;
        }
        path.push_back(node->val);
        if (node->left==NULL && node->right==NULL)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        dfs(node->left,path);
        dfs(node->right,path);
        path.pop_back();
        return;
        
        
    }
};
// @lc code=end

