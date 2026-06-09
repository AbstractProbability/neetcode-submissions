class Solution {
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
public:
    bool checkpresence(vector<vector<char>> &board, 
                                                vector<vector<bool>> &visited,
                                                int i, int j,
                                                string word)
    {
        if (board[i][j] != word[0]) { return false; }
        if (word.size() == 1) { return true; }
        // cout << word[0] << " " << i << " " << j << "\n";
        visited[i][j] = true;
        for (int k = 0; k<4; k++) {
            int nrow = i+dx[k], ncol = j+dy[k];
            if (nrow < board.size() && nrow >= 0
                    && ncol < board[0].size() && ncol >= 0
                    && !visited[nrow][ncol]
                    && checkpresence(board, visited, nrow, ncol, word.substr(1)))
            { return true; }
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (checkpresence(board, visited, i, j, word)) { return true; }
            }
        }
        return false;
    }
};
