class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> mp;
        vector<int> ret;
        int curr = nums[0], num_curr = 1;
        for (int i = 1; i<nums.size(); i++) {
            if (nums[i] == curr) {
                num_curr++;
            } else {
                mp.push_back({num_curr, curr});
                curr = nums[i];
                num_curr = 1;
            }
        }
        mp.push_back({num_curr, curr});
        
        // cout << mp[0].second << "\n";
        sort(mp.begin(), mp.end());
        int n = mp.size();
        for (int i = mp.size()-1; i>=n-k; i--) {
            ret.push_back(mp[i].second);
        }
        return ret;
    }
};
