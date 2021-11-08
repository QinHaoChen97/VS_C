// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem226.h"

using namespace std;
// @before-stub-for-debug-end





/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
#include<queue>
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr)
        {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
                TreeNode* node=q.front();
                q.pop();
                if(node!=nullptr)
                {
                    TreeNode* switchnode=node->left;
                    node->left=node->right;
                    node->right=switchnode;
                    q.push(node->left);
                    q.push(node->right);
                }
        }
        return root;
        
        
    }
};
// @lc code=end

