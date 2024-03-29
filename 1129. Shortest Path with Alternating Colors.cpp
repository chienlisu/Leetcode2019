class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);

        for (auto& v : red_edges)
            red[v[0]].push_back(v[1]);
        for (auto& v : blue_edges)
            blue[v[0]].push_back(v[1]);

        const int INF = 10000;

        vector<int> dist(n * 2, INF);
        queue<tuple<int, int, bool>> Q; // (distance, vertex, color)

        dist[0] = 0;
        dist[1] = 0;
        Q.emplace(0, 0, false);
        Q.emplace(0, 0, true);
        while (!Q.empty()) {
            int d, u;
            bool c;

            tie(d, u, c) = Q.front();
            Q.pop();

            c = !c; // toggle color
            if (!c) {
                for (int v : red[u]) {
                    if (d + 1 < dist[v * 2 + c]) {
                        Q.emplace(d + 1, v, c);
                        dist[v * 2 + c] = d + 1;
                    }
                }
            } else {
                for (int v : blue[u]) {
                    if (d + 1 < dist[v * 2 + c]) {
                        Q.emplace(d + 1, v, c);
                        dist[v * 2 + c] = d + 1;
                    }
                }
            }
        }

        vector<int> res(n);
        for (int i = 1; i < n; i++) {
            int t = min(dist[i * 2], dist[i * 2 + 1]);
            if (t == INF)
                res[i] = -1;
            else
                res[i] = t;
        }

        return res;
    }
};
