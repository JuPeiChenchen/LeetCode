/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> que;
        stack<int> st;
        int result = 0;
        for(int i = students.size() - 1; i >= 0; i--) {
            que.push(students[i]);

        }
        for(int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
        int count = 0;
        while(!que.empty() && !st.empty()) {
            if(count == que.size()) {
                return count;
            }
            int a = que.front();
            int b = st.top();
            if(a == b) {
                que.pop();
                st.pop();
                count = 0;
            }
            else {
                que.pop();
                que.push(a);
                count++;
            }
        }
        return 0;
    }
};
// @lc code=end

