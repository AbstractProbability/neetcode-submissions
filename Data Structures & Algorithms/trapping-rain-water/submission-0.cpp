class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre_max(n);
        int cmax = -1001;
        for (int i = 0; i<n; i++) {
            pre_max[i] = max(cmax, height[i]);
            cmax = pre_max[i];
        }
        cmax = -1001;
        int total_trapped = 0;
        for (int i = n-1; i>=0; i--) {
            cmax = max(cmax, height[i]);
            int trapped_above = max(0, min(cmax, pre_max[i])-height[i]);
            total_trapped += trapped_above;
        }
        return total_trapped;
    }
};
