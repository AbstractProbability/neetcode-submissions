class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        const int INF = INT_MAX;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++) {
                int crow = row+dx[i], ccol = col+dy[i];
                if (crow >= 0 && crow < grid.size()
                        && ccol >= 0 && ccol < grid[0].size()
                        && grid[crow][ccol] == INF && !visited[crow][ccol]
                ) {
                    q.push({crow, ccol});
                    visited[crow][ccol] = true;
                    grid[crow][ccol] = grid[row][col]+1;
                }
            }
        }
    }
};
