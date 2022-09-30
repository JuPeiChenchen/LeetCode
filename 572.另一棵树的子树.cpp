// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem572.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
/*class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if(!root) {
            return false;
        }
        return isSameTree(root, subRoot) ||  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        return dfs(root,subRoot);
        //return isSameTree(root, subRoot) ||  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p) return false;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        //if(p->val != q->val) return fasle;
        st1.push(p);
        st2.push(q);
        while(!st1.empty() && !st2.empty()) {
            TreeNode* a = st1.top();
            st1.pop();
            TreeNode* b = st2.top();
            st2.pop();
            if(!a && !b) continue;
            if(!a || !b || a->val != b->val) return false;
            st1.push(a->left);
            st1.push(a->right);
            st2.push(b->left);
            st2.push(b->right);
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            if(node->val == subRoot->val) {
                if(isSameTree(node, subRoot)) {
                    return true;
                }
            }
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return false;
    }
};

// @lc code=end

