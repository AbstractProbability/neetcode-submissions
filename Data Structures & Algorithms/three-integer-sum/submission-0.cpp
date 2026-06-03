class Solution {
public:
    bool same_idx(int a, int b, int c) {
        if (a == b || a == c || b == c) {
            return true;
        }
        return false;
    }

    bool one_two_five(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        if (a == 1 && b == 2 && c == 5) {
            return true;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {        
        set<pair<pair<int, int>, int>> s;
        int n = nums.size(), target, l, r;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i<n; i++) {
            target = -nums[i];
            l = 0, r = n-1;
            while (l < r) {
                // if (one_two_five(i, l, r)) { cout << "ok\n"; }
                if (nums[l]+nums[r] < target) {
                    l++;
                } else if (nums[l]+nums[r] > target) {
                    r--;
                } else {
                    // cout << nums[l] << " " << nums[r] << " " << -target << "\n";
                    if (!same_idx(i, l, r)) {
                        vector<int> v = {nums[l], nums[r], -target};
                        sort(v.begin(), v.end());
                        s.insert({{v[0], v[1]}, v[2]});
                    }
                    l++; r--;
                }
            }
        }
        
        for (auto three: s) {
            vector<int> v = {three.first.first, three.first.second, three.second};
            ret.push_back(v);
        }
        
        return ret;
    }
};
