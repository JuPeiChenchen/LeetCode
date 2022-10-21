/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int ans = 1;
        while (!stk.empty() && stk.top().first <= price) {
            ans += stk.top().second;
            stk.pop();
        }
        stk.push({price, ans});
        return ans;
    }

private:
    stack<pair<int, int>> stk;
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

