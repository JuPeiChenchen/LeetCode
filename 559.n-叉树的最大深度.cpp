/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*class Solution {
public:
    int result;
    int getdepth(Node* root) {
        if(root == NULL) return 0;
        int a = 0;
        for(int i = 0; i < root->children.size(); i++) {
            int leftDepth = getdepth(root->children[i]);
            a = a > leftDepth ? a : leftDepth;
        }
        
        return 1 + a;
    }
    int maxDepth(Node* root) {
        result = 0;
        if(root == NULL) return result;
        result = getdepth(root);
        return result;
    }
};*/
class Solution {
public:
    int result;
    void getdepth(Node* root, int depth) {
        result = result > depth ? result : depth;
        if(root->children.size() == 0) return;
        for(int i = 0; i < root->children.size(); i++) {
            getdepth(root->children[i], depth + 1);
        }
        return ;
    }
    int maxDepth(Node* root) {
        result = 0;
        if(root == NULL) return result;
        getdepth(root, 1);
        return result;
    }
};
// @lc code=end

