/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> result;
    void traversal(TreeNode* root, int target, int count, vector<int>& vec) {
        if(!root->left && !root->right && count == 0) {
            result.push_back(vec);
        }
        if(!root->left && !root->right) {
            return;
        }
        if(root->left) {
            vec.push_back(root->left->val);
            traversal(root->left, target, count - root->left->val, vec);
            vec.pop_back();
        }
        if(root->right) {
            vec.push_back(root->right->val);
            traversal(root->right, target, count - root->right->val, vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return result;
        vector<int> vec;
        vec.push_back(root->val);
        traversal(root, targetSum, targetSum - root->val, vec);
        return result;
    }
};
// @lc code=end

