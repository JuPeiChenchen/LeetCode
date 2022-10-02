/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int flag = -1;
    void summ(TreeNode* root, int targetSum, int sum) {
        if(root == NULL) return;
        if(flag == 1) return;
        //cout<<sum<<endl;
        sum += root->val;
        //cout<<sum<<endl;
        if(sum == targetSum && root->left == NULL && root->right == NULL) {flag = 1;return;}
        if(root->left) {
            summ(root->left, targetSum, sum);
            //sum -= root->left->val;
            //cout<<"+++"<<endl;
        }
        if(root->right) {
           // cout<<root->right->val<<endl;
            summ(root->right, targetSum, sum);
            //sum -= root->right->val;
            //cout<<"-----"<<endl;
        }
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        summ(root, targetSum, 0);
        if(flag == 1) return true;
        return false;
    }
};
/*class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // 遇到叶子节点，并且计数为0
        if (!cur->left && !cur->right) return false; // 遇到叶子节点直接返回

        if (cur->left) { // 左
            count -= cur->left->val; // 递归，处理节点;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }
        if (cur->right) { // 右
            count -= cur->right->val; // 递归，处理节点;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // 回溯，撤销处理结果
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
};*/
// @lc code=end

