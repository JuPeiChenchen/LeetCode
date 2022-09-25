/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> itIn;
    stack<int> itOut;
    MyQueue() {

    }
    
    void push(int x) {
        itIn.push(x);
    }
    
    int pop() {
        if(itOut.empty()) {
            while(!itIn.empty()) {
                int x = itIn.top();
                itIn.pop();
                itOut.push(x);
            }
        }
        int result = itOut.top();
        itOut.pop();
        return result;
    }
    
    int peek() {
        if(itOut.empty()) {
            while(!itIn.empty()) {
                int x = itIn.top();
                itIn.pop();
                itOut.push(x);
            }
        }
        int result = itOut.top();
        return result;
    }
    
    bool empty() {
        if(itIn.empty() && itOut.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

