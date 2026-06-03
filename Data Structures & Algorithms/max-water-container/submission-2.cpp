class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxa = INT_MIN;
        int l = 0, r = heights.size()-1;
        while (l < r) {
            maxa = max(maxa,  (r-l)*min(heights[r], heights[l]));
            if (heights[r] == min(heights[l], heights[r])) { r--; }
            else { l++; }
        }
        return maxa;
    }
};
