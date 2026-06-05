class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int total = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (visited[i][j]) {
                    continue;
                }
                q.push({i, j});
                total++;
                visited[i][j] = true;
                while (!q.empty()) {
                    int row = q.front().first, col = q.front().second;
                    q.pop();
                    for (int k = 0; k<4; k++) {
                        int crow = row+dx[k], ccol = col+dy[k];
                        if (crow >= 0 && crow<grid.size()
                                && ccol >= 0 && ccol<grid[0].size()
                                && grid[crow][ccol] == '1'
                                && !visited[crow][ccol]
                        ) {
                            q.push({crow, ccol});
                            visited[crow][ccol] = true;
                        }
                    }
                }
            }
        } 

        return total;
    }
};
