class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int max_area = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (visited[i][j]) {
                    continue;
                }
                int area = 1;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    int row = q.front().first, col = q.front().second;
                    q.pop();
                    for (int k = 0; k<4; k++) {
                        int crow = row+dx[k], ccol = col+dy[k];
                        if (crow >= 0 && crow<grid.size()
                                && ccol >= 0 && ccol<grid[0].size()
                                && grid[crow][ccol] == 1
                                && !visited[crow][ccol]
                        ) {
                            q.push({crow, ccol});
                            visited[crow][ccol] = true;
                            area++;
                        }
                    }
                }
                max_area = max(max_area, area);
            }
        } 

        return max_area;
    }
};
