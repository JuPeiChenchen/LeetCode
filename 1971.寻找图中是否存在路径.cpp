/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &&edge : edges) {
            int x = edge[0], y = edge[1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<bool> visited(n, false);
        queue<int> qu;
        qu.emplace(source);
        visited[source] = true;
        while (!qu.empty()) {
            int vertex = qu.front();
            qu.pop();
            if (vertex == destination) {
                break;
            }
            for (int next: adj[vertex]) {
                if (!visited[next]) {
                    qu.emplace(next);
                    visited[next] = true;
                }
            }
        }
        return visited[destination];
    }
};
/*
class Solution {
public:
    bool dfs(int source, int destination, vector<vector<int>> &adj, vector<bool> &visited) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int next : adj[source]) {
            if (!visited[next] && dfs(next, destination, adj, visited)) {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int x = edge[0], y = edge[1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};
*/
/*class UnionFind {
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool connect(int x, int y) {
        return find(x) == find(y);
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }
        UnionFind uf(n);
        for (auto edge : edges) {
            uf.uni(edge[0], edge[1]);
        }
        return uf.connect(source, destination);
    }
};
*/
// @lc code=end

