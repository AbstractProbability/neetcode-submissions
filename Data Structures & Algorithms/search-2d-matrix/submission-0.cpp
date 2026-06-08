class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = rows*cols-1;
        while (l <= r) {
            int m = l+(r-l)/2;
            int mrow = m/cols, mcol = m%cols;
            int lrow = l/cols, lcol = l%cols;
            int rrow = r/cols, rcol = r%cols;
            if (matrix[mrow][mcol] == target) { return true; }
            else if (matrix[mrow][mcol] > target) { r = m-1; }
            else { l = m+1; }
        }
        return false;
    }
};
