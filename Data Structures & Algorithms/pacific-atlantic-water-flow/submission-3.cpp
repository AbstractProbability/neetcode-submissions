class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ret;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), 0));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        for (int i = 0; i<heights.size(); i++) {
            q.push({i, 0});
            visited[i][0] = true;
        }
        for (int i = 1; i<heights[0].size(); i++) {
            q.push({0, i});
            visited[0][i] = true;
        }
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++) {
                int crow = row+dx[i], ccol = col+dy[i];
                if (
                    crow >= 0 && crow < heights.size()
                    && ccol >= 0 && ccol < heights[0].size()
                    && !visited[crow][ccol]
                    && heights[crow][ccol] >= heights[row][col]
                ) {
                    q.push({crow, ccol});
                    visited[crow][ccol] = true;
                }
            }
            pacific[row][col] = true;
        }
        fill(visited.begin(), visited.end(), vector<bool>(heights[0].size(), false));
        for (int i = 0; i<heights.size(); i++) {
            q.push({i, heights[0].size()-1});
            visited[i][heights[0].size()-1] = true;
        }
        for (int i = 0; i<heights[0].size()-1; i++) {
            q.push({heights.size()-1, i});
            visited[heights.size()-1][i] = true;
        }
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++) {
                int crow = row+dx[i], ccol = col+dy[i];
                if (
                    crow >= 0 && crow < heights.size()
                    && ccol >= 0 && ccol < heights[0].size()
                    && !visited[crow][ccol]
                    && heights[crow][ccol] >= heights[row][col]
                ) {
                    q.push({crow, ccol});
                    visited[crow][ccol] = true;
                }
            }
            if (pacific[row][col]) { ret.push_back({row, col}); }
        }

        return ret;
    }

    
};
