/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> result;
        if(root != NULL) st.push(root);
        while(!st.empty()) {
            Node* p = st.top();
            st.pop();
            for(int i = p->children.size() - 1; i >= 0; i--) {
                st.push(p->children[i]);
            }
            result.push_back(p->val);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> result;
        if(root != NULL) st.push(root);
        while(!st.empty()) {
            Node* p = st.top();
            st.pop();
            for(int i = p->children.size() - 1; i >= 0; i--) {
                st.push(p->children[i]);
            }
            result.push_back(p->val);
        }
        return result;
    }
};
/*class Solution {
public:
    void helper(const Node* root, vector<int> & res) {
        if (root == nullptr) {
            return;
        }
        res.emplace_back(root->val);
        for (auto & ch : root->children) {
            helper(ch, res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};
*/
// @lc code=end

