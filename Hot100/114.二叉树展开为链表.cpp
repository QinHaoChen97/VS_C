// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem114.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
#include<stack>
using namespace std;
//栈还是会用到额外的空间
//原地算法可以看这个https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
class Solution {
public:
    void flatten(TreeNode* root) {  
        if (root==nullptr)
        {
            return;
        }
        stack<TreeNode*> sta_for_treenode;
        sta_for_treenode.push(root);
        while (!sta_for_treenode.empty())
        {
            TreeNode* node=sta_for_treenode.top();
            sta_for_treenode.pop();
            if (node->right!=nullptr)  //先序遍历的迭代法需要先压入右节点
            {
                sta_for_treenode.push(node->right);
            }
            if (node->left!=nullptr)        
            {
                sta_for_treenode.push(node->left);
            }
            node->left=nullptr;
            node->right=(sta_for_treenode.empty())?nullptr:sta_for_treenode.top();
        }
        return;
        

    }
};
// @lc code=end

