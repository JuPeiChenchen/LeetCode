/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
private:
    int n = 1005; // 节点数量3 到 1000
    int father[1005];

    // 并查集初始化
    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根，本题用不上
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (same(edges[i][0], edges[i][1])) return edges[i];
            else join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};
/*
int n = 1003;
int father[n];
void init(int u) {
    father[u] = u;
}
int find(int u) {
    return father[u] == u ? u : father[u] = find(father[u]);
}
int join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    father[v] = u;
}
int same(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}
*/
// @lc code=end

