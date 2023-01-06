/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int result = 0;
    int path = 0;
public:
    void traversal(TreeNode* root ){
        if(root) {
            path = path * 10 + root->val;
        }
        if(root->left == NULL && root->right == NULL) {
            result += path;
            cout<<path<<endl;
            path /= 10;
            return;
        }
        traversal(root->left);
        traversal(root->right);
        if(path >= 10) path /= 10;
    }
    int sumNumbers(TreeNode* root) {
        traversal(root);
        return result;
    }
};*/
class Solution {
private:
    int result;
    vector<int> path;
    // 把vector转化为int
    int vectorToInt(const vector<int>& vec) {
        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum = sum * 10 + vec[i];
        }
        return sum;
    }
    void traversal(TreeNode* cur) {
        if (!cur->left && !cur->right) { // 遇到了叶子节点
            result += vectorToInt(path);
            return;
        }

        if (cur->left) { // 左 （空节点不遍历）
            path.push_back(cur->left->val);     // 处理节点
            traversal(cur->left);               // 递归
            path.pop_back();                    // 回溯，撤销
        }
        if (cur->right) { // 右 （空节点不遍历）
            path.push_back(cur->right->val);    // 处理节点
            traversal(cur->right);              // 递归
            path.pop_back();                    // 回溯，撤销
        }
        return ;
    }
public:
    int sumNumbers(TreeNode* root) {
        path.clear();
        if (root == nullptr) return 0;
        path.push_back(root->val);
        traversal(root);
        return result;
    }
};
// @lc code=end

