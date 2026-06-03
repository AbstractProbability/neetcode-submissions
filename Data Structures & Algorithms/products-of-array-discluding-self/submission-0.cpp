class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), ret(n, 0);
        int curr = 1;
        for (int i = 0; i<n; i++) {
            pre[i] = curr;
            curr *= nums[i];
        }
        curr = 1;
        for (int i = n-1; i>=0; i--) {
            ret[i] = pre[i]*curr;
            curr *= nums[i];
        }
        return ret;
    }
};
