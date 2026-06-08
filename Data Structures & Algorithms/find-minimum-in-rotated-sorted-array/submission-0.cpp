class Solution {
public:
    int findMin(vector<int> &nums) {
        int cmin = nums[0];
        int l = 1, r = nums.size()-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] < cmin) {
                cmin = nums[m];
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return cmin;
    }
};
