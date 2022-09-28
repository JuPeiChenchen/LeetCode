/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            TreeNode* a = NULL;
            for(int i = 0; i < size; i++) {
                a = que.front();
                que.pop();
                if(a->left) que.push(a->left);
                if(a->right) que.push(a->right);
            }
            result.push_back(a->val);
        }
        return result;
    }
};
// @lc code=end

