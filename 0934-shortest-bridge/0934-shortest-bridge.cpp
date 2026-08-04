class Solution {
public:
    int n;
    vector<vector<int>> visited;
    queue<pair<int,int>> q;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void dfs(vector<vector<int>>& grid, int x, int y) {
        visited[x][y] = 1;
        q.push({x, y});

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (visited[nx][ny] || grid[nx][ny] == 0)
                continue;

            dfs(grid, nx, ny);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        visited.assign(n, vector<int>(n, 0));

        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    found = true;
                    break;
                }
            }
        }

        int step = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;

                    if (visited[nx][ny])
                        continue;

                    // Gặp đảo thứ hai
                    if (grid[nx][ny] == 1)
                        return step;

                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            step++;
        }

        return -1;
    }
};