class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i<nums.size(); i++) {
            auto found = mp.find(target-nums[i]);
            if (found != mp.end()) {
                return vector<int>({found->second, i});
            }
            mp.insert({nums[i], i});
        }
    }
};
