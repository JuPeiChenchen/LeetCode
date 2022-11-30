/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }

    int pop() {
        int val = group[maxFreq].top();
        freq[val]--;
        group[maxFreq].pop();
        if (group[maxFreq].empty()) {
            maxFreq--;
        }
        return val;
    }

private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

