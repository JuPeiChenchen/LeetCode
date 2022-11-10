/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */

// @lc code=start
class Solution {
public:
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int k = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                // 累加钥匙数量
                if (islower(c)) ++k;
                // 起点
                else if (c == '@') si = i, sj = j;
            }
        }
        queue<tuple<int, int, int>> q{{{si, sj, 0}}};
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << k)));
        vis[si][sj][0] = true;
        int ans = 0;
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                auto [i, j, state] = q.front();
                q.pop();
                // 找到所有钥匙，返回当前步数
                if (state == (1 << k) - 1) return ans;
                // 往四个方向搜索
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    // 在边界范围内
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        char c = grid[x][y];
                        // 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (c == '#' || (isupper(c) && (state >> (c - 'A') & 1) == 0)) continue;
                        int nxt = state;
                        // 是钥匙，更新状态
                        if (islower(c)) nxt |= 1 << (c - 'a');
                        // 此状态未访问过，入队
                        if (!vis[x][y][nxt]) {
                            vis[x][y][nxt] = true;
                            q.push({x, y, nxt});
                        }
                    }
                }
            }
            // 步数加一
            ++ans;
        }
        return -1;
    }
};
/*class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    struct State {
        int x;
        int y;
        int key;
    };
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // 先找到起点，以及钥匙的数量
        State start; 
        int keycnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start.x = i;
                    start.y = j;
                    start.key = 0;
                }
                if (islower(grid[i][j])) {
                    keycnt++;
                }
            }
        }
        
        // BFS
        queue<State> q;
        q.push(start);
        int allkey = (1 << keycnt) - 1; // 表示所有钥匙都找到的状态
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(allkey + 1, false)));
        int step = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                State cur = q.front();
                q.pop();
                
                // 如果所有钥匙都找到
                if (cur.key == allkey) return step;
                
                // 遍历下一个状态
                for (int k = 0; k < 4; k++) {
                    int x = cur.x + dx[k], y = cur.y + dy[k];
                    if (x < 0 || y < 0 || x >= m || y >= n) continue;
                    
                    char c = grid[x][y];
                    int key = cur.key;
                    
                    if (c == '#') continue;
                    if (isupper(c) && (key >> (c - 'A') & 1) == 0) continue;
                    
                    if (islower(c)) {
                        key |= 1 << (c - 'a');
                    }
                    if (visited[x][y][key] == true) continue;
                    
                    visited[x][y][key] = true; 
                    q.push(State{x, y, key}); 
                } 
            }
            step++;
        }
        return -1;
    }
};*/
// @lc code=end

