class Solution {
public:
    void recurse(vector<int> &nums,
                                int target,
                                int start,
                                vector<vector<int>> &ret,
                                vector<int> &curr)
    {
        for (int i = start; i<nums.size(); i++) {
            if (nums[i] <= target) {
                curr.push_back(nums[i]);
                if (nums[i] < target) { recurse(nums, target-nums[i], i, ret, curr); }
                else { ret.push_back(curr); }
                curr.pop_back();
            } else { return; }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        vector<int> curr;
        recurse(nums, target, 0, ret, curr);
        return ret;
    }
};
