// https://leetcode.com/problems/find-the-safest-path-in-a-grid

class Solution {
public:
    const static int MXN = 4e2;
    int N;
    vector<vector<int>> g;

    void fill(int i, int j) {
        queue<pair<int, int>> q;
        vector<vector<int>> d(N, vector<int>(N, INT_MAX));
        q.push({i, j});
        d[i][j] = 0, g[i][j] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x + 1 < N && d[x + 1][y] == INT_MAX) {
                d[x + 1][y] = d[x][y] + 1;
                if (g[x + 1][y] >= d[x + 1][y]) {
                    g[x + 1][y] = min(g[x + 1][y], d[x + 1][y]);
                    q.push({x + 1, y});
                }
            }
            if (y + 1 < N && d[x][y + 1] == INT_MAX) {
                d[x][y + 1] = d[x][y] + 1;
                if (g[x][y + 1] >= d[x][y + 1]) {
                    g[x][y + 1] = min(g[x][y + 1], d[x][y + 1]);
                    q.push({x, y + 1});
                }
            }
            if (x - 1 >= 0 && d[x - 1][y] == INT_MAX) {
                d[x - 1][y] = d[x][y] + 1;
                if (g[x - 1][y] >= d[x - 1][y]) {
                    g[x - 1][y] = min(g[x - 1][y], d[x - 1][y]);
                    q.push({x - 1, y});
                }
            }
            if (y - 1 >= 0 && d[x][y - 1] == INT_MAX) {
                d[x][y - 1] = d[x][y] + 1;
                if (g[x][y - 1] >= d[x][y - 1]) {
                    g[x][y - 1] = min(g[x][y - 1], d[x][y - 1]);
                    q.push({x, y - 1});
                }
            }
        }
    }

    int lastTrue(int lo, int hi, function<bool(int)> f) {
        lo--;
        for (int dif = hi - lo; dif > 0; dif /= 2) {
            while (lo + dif <= hi && f(lo + dif)) {
                lo += dif;
            }
        }
        return lo;
    }

    bool dfs(int x, int y, vector<bitset<MXN>>& visited, int k) {
        visited[x][y] = true;

        bool ans = (x == N - 1 && y == N - 1 && g[x][y] >= k);
        if (x + 1 < N && !visited[x + 1][y] && g[x + 1][y] >= k && !ans)
            ans |= dfs(x + 1, y, visited, k);
        if (y + 1 < N && !visited[x][y + 1] && g[x][y + 1] >= k && !ans)
            ans |= dfs(x, y + 1, visited, k);
        if (x - 1 >= 0 && !visited[x - 1][y] && g[x - 1][y] >= k && !ans)
            ans |= dfs(x - 1, y, visited, k);
        if (y - 1 >= 0 && !visited[x][y - 1] && g[x][y - 1] >= k && !ans)
            ans |= dfs(x, y - 1, visited, k);

        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        N = (int)grid.size();
        g = vector<vector<int>>(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j])
                    fill(i, j);

        return lastTrue(0, 2 * N - 1, [&](int k) -> bool {
            vector<bitset<MXN>> visited(N);
            return (g[0][0] >= k && dfs(0, 0, visited, k));
        });
    }
};