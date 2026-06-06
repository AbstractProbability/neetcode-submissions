class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        queue<pair<int, int>> q;
        for (int i = 0; i<board.size(); i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0}); visited[i][0] = true;
            }
            if (board[i][board[0].size()-1] == 'O') {
                q.push({i, board[0].size()-1}); visited[i][board[0].size()-1] = true;
            }
        }
        for (int i = 1; i<board[0].size()-1; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i}); visited[0][i] = true;
            }
            if (board[board.size()-1][i] == 'O') {
                q.push({board.size()-1, i}); visited[board.size()-1][i] = true;
            }
        }

        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int i = 0; i<4; i++) {
                int crow = row+dx[i], ccol = col+dy[i];
                if (
                    crow >= 0 && crow < board.size()
                    && ccol >= 0 && ccol < board[0].size()
                    && !visited[crow][ccol]
                    && board[crow][ccol] == 'O'
                ) {
                    q.push({crow, ccol});
                    visited[crow][ccol] = true;
                }
            }
        }

        for (int i = 0; i<board.size(); i++) {
            for (int j = 0; j<board[0].size(); j++) {
                if (board[i][j] == 'O' && !visited[i][j]) { board[i][j] = 'X'; }
            }
        }
    }
};
