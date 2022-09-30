/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        if(root != NULL) {
            st.push(root);
        }
        vector<int> result;
        while(!st.empty()) {
            Node* q = st.top();
            st.pop();
            for(int i = 0; i < q->children.size(); i++) {
                st.push(q->children[i]);
            }
            result.push_back(q->val);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};*/
class Solution {
public:
    void helper(Node* cur, vector<int>& result) {
        if(cur == NULL) return;
        for(int i = 0; i < cur->children.size(); i++) {
            helper(cur->children[i], result);
            
        }
        result.push_back(cur->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

};
// @lc code=end

