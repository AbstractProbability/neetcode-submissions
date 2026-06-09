class Solution {
public:
    void recurse(vector<int> nums,
                                int target,
                                vector<vector<int>> &ret,
                                vector<int> &curr)
    {
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i]) {
                if (i <= target) {
                    curr.push_back(i);
                    nums[i]--;
                    if (i < target) { recurse(nums, target-i, ret, curr); }
                    else { ret.push_back(curr); }
                    nums[i]++;
                    curr.pop_back();
                } else { return; }
                nums[i] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums(51, 0);
        for (int i = 0; i<candidates.size(); i++) {
            nums[candidates[i]]++;
        }
        vector<vector<int>> ret;
        vector<int> curr;
        recurse(nums, target, ret, curr);
        return ret;
    }
};
