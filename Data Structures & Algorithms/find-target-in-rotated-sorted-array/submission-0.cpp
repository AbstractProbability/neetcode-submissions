class Solution {
public:
    int findMin(vector<int> &nums) {
        int cmin = 0;
        int l = 1, r = nums.size()-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] < nums[cmin]) {
                cmin = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return cmin;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minidx = findMin(nums);
        cout << minidx << "\n";
        int l, r;
        if (target >= nums[0]) {
            l = 0, r = minidx-1;
            if (r < 0) { r = n-1; }
        } else {
            l = minidx, r = n-1;
        }
        cout << l << " " << r << "\n";
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) { return m; }
            else if (nums[m] < target) { l = m+1; }
            else { r = m-1; }
        }
        return -1;
    }
};
