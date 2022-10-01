/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        int result = 0;
        if(root == NULL) return result;
        stack<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* p = que.top();
            que.pop();
            result++;
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
        return result;
    }
};*/
/*class Solution {
public:
    int getnum(TreeNode* root, int num) {
        if(root == NULL) return 0;
        int leftNum = getnum(root->left, num + 1);
        int rightNum =  getnum(root->right, num + 1);
        return leftNum + rightNum + 1;
    }
    int countNodes(TreeNode* root) {
        int result = 0;
        result = getnum(root, 0);
        return result;
    }
};*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便
        while (left) {  // 求左子树深度
            left = left->left;
            leftDepth++;
        }
        while (right) { // 求右子树深度
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

