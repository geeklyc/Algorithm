//
//  BTree.cpp
//  Algorithm
//
//  Created by liyoucheng on 2022/4/22.
//

#include "BTree.hpp"

#include <queue.h>
#include <stack.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // 层序遍历
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<int> que;
        
        if (root != nullptr) {
            // 入队
            que.push(root);
        }
        
        vector<vector<int>> res;
        while (!que.empty()) {
            // 出队
            TreeNode node = que.pop();
                     // 保存结果
            res.push_back(node->val);
            
            if (node->left != nullptr) {
                que.push(node->left);
            }
            
            if (node->right != nullptr) {
                que.push(node->right);
            }
        }
        return res;
    }
    // 中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        stack<TreeNode *> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            
            if (!stk.empty()) {
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        
        return res;
    }
    // 前序
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        stack<TreeNode *> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            
            if (!stk.empty()) {
                root = stk.top();
                stk.pop();
                root = root->right;
            }
        }
        return res;
    }
    // 后序
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            
            if (!stk.empty()) {
                root = stk.top();
                // 右子树到头
                if (root->right == nullptr || root->right == prev) {
                    stk.pop();
                    res.push_back(root->val);
                    prev = root;
                    root = nullptr;
                } else {
                    root = root->right;
                }
            }
        }
        return res;
    }
    void dfs(TreeNode *node, vector<int> &res) {
        if (node == nullptr) {
            return;
        }
        
        dfs(node->left, res);
        dfs(node->right, res);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};


