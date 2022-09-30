// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem100.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
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
};
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
};
*/
// @lc code=end

