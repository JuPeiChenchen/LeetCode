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
/*class Solution {
public:
    bool compare(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == NULL && tree2 != NULL) return false;
        else if (tree1 != NULL && tree2 == NULL) return false;
        else if (tree1 == NULL && tree2 == NULL) return true;
        else if (tree1->val != tree2->val) return false; // 注意这里我没有使用else

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool left = compare(tree1->left, tree2->left);   // 左子树：左、 右子树：左
        bool right = compare(tree1->right, tree2->right);  // 左子树：右、 右子树：右
        bool isSame = left && right;                    // 左子树：中、 右子树：中（逻辑处理）
        return isSame;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};*/
// @lc code=end

