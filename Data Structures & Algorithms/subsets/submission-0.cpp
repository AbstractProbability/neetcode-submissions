class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int maxn = (1 << nums.size());
        for (int i = 0; i<maxn; i++) {
            vector<int> curr;
            for (int j = 0; j<32; j++) {
                if ((1<<j)&i) { curr.push_back(nums[j]); }
            }
            ret.push_back(curr);
        }
        return ret;
    }
};
