class Solution {
public:
    int DFS(int x, int parent, int path_sum, int signalSpeed,
            const vector<vector<pair<int, int>>>& g) {
        int cnt = path_sum % signalSpeed == 0;

        for (auto &[y, wt] : g[x]) {
            if (y != parent)
                cnt += DFS(y, x, path_sum + wt, signalSpeed, g);
        }

        return cnt;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        // Connectable:
            // a < b, a != b != c
            // dist{c, a} % signalSpeed == 0
            // dist{c, b} % signalSpeed == 0
            // path{c, b} || path{c, a} do not share any edges (not overlapped?)
        // Target: vec of server pairs that are connectable through server i
        int n = edges.size() + 1;
        // {a_i, {b_i, wt_i}}
        vector<vector<pair<int, int>>> g(n);
        vector<int> ret(n);

        for (auto &e: edges) {
            int x = e[0], y = e[1], wt = e[2];
            g[x].push_back({y, wt});
            g[y].push_back({x, wt});
        }

        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1)
                continue;
            
            int sum = 0;
            for (auto &[y, wt] : g[i]) { // structured binding since c17
                int cnt = DFS(y, i, wt, signalSpeed, g);
                ret[i] += cnt * sum;
                sum += cnt;
            }
        }

        return ret;
    }
};