/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
private:
    void dfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        if (visited[key]) {
            return;
        }
        visited[key] = true;
        vector<int> keys = rooms[key];
        for (int key : keys) {
            // 深度优先搜索遍历
            dfs(rooms, key, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, 0, visited);
        //检查是否都访问到了
        for (int i : visited) {
            if (i == false) return false;
        }
        return true;
    }
};
/*class Solution {
private:  
    void dfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        vector<int> keys = rooms[key];
        for (int key : keys) { 
            if (visited[key] == false) {
                visited[key] = true;
                dfs(rooms, key, visited);
            }       
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false); 
        visited[0] = true; // 0 节点是出发节点，一定被访问过
        dfs(rooms, 0, visited);  
        //检查是否都访问到了
        for (int i : visited) {
            if (i == false) return false;
        }
        return true;
    }
};*/
// @lc code=end

