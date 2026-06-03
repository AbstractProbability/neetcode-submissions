class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++) {
            vector<bool> freq(9, false);
            for (int j = 0; j<9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (freq[board[i][j]-'1']) {
                    return false;
                }
                freq[board[i][j]-'1'] = true;
            }
        }
        for (int i = 0; i<9; i++) {
            vector<bool> freq(9, false);
            for (int j = 0; j<9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (freq[board[j][i]-'1']) {
                    return false;
                }
                freq[board[j][i]-'1'] = true;
            }
        }
        for (int i = 0; i<9; i++) {
            vector<bool> freq(9, false);
            for (int j = 0; j<9; j++) {
                int row = j/3 + 3*(i/3);
                int col = j%3 + 3*(i%3);
                if (board[row][col] == '.') {
                    continue;
                }
                if (freq[board[row][col]-'1']) {
                    return false;
                }
                freq[board[row][col]-'1'] = true;
            }
        }
        return true;
    }
};
