/*
 * @lc app=leetcode.cn id=1697 lang=cpp
 *
 * [1697] 检查边长度限制的路径是否存在
 */

// @lc code=start
// 并查集模板，包含路径压缩（参考 findset 函数）以及按秩合并（参考 sz 变量）
class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;
    
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    
    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // 将 queries 按照边权限制从小到大排序
        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int i, int j) {
            return queries[i][2] < queries[j][2];
        });
        
        // 将 edgeList 按照边权从小到大排序
        sort(edgeList.begin(), edgeList.end(), [](const auto& e1, const auto& e2) {
            return e1[2] < e2[2];
        });
        
        // 并查集
        UF uf(n);
        
        int i = 0;
        vector<bool> ans(queries.size());
        for (int query: qid) {
            // 往并查集中添加边直到边权关系 dis_i < limit_j 不满足
            while (i < edgeList.size() && edgeList[i][2] < queries[query][2]) {
                uf.unite(edgeList[i][0], edgeList[i][1]);
                ++i;
            }
            // 使用并查集判断连通性
            ans[query] = uf.connected(queries[query][0], queries[query][1]);
        }
        
        return ans;
    }
};

// @lc code=end

