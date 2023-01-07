/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
private:
    vector<int> vec;
    // 有序树转成有序数组
    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        vec.push_back(cur->val);
        traversal(cur->right);
    }
    // 有序数组转平衡二叉树
    TreeNode* getTree(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = getTree(nums, left, mid - 1);
        root->right = getTree(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        traversal(root);
        return getTree(vec, 0, vec.size() - 1);
    }
};
// @lc code=end

