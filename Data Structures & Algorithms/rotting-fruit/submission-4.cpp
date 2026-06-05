class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int ones = 0, twos = 0;
        for (int i = 0; i<grid.size(); i++)
            for (int j = 0; j<grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    ones++;
                } else if (grid[i][j] == 2) {
                    twos++;
                    q.push({i, j});
                    visited[i][j] = true;
                }
        
        if (ones == 0) { return 0; }
        else {
            if (twos == 0) { return -1; }
        }
        int time = INT_MIN;
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++) {
                int crow = row+dx[i], ccol = col+dy[i];
                if (crow >= 0 && crow < grid.size()
                        && ccol >= 0 && ccol < grid[0].size()
                        && grid[crow][ccol] == 1 && !visited[crow][ccol]
                ) {
                    q.push({crow, ccol});
                    visited[crow][ccol] = true;
                    grid[crow][ccol] = grid[row][col]+1;
                }
            }
        }
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                time = max(time, grid[i][j]-2);
            }
        }
        return time;
    }
};
