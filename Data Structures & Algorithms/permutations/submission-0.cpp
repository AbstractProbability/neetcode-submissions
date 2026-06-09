class Solution {
public:
    void recurse(vector<int> &nums,
                                int nvisited,
                                vector<bool> &visited,
                                vector<vector<int>> &ret,
                                vector<int> &curr)
    {
        if (nvisited == nums.size()) {
            ret.push_back(curr);
        }
        for (int i = 0; i<nums.size(); i++) {
            if (!visited[i]) {
                curr.push_back(nums[i]);
                visited[i] = true;
                recurse(nums, nvisited+1, visited, ret, curr);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        recurse(nums, 0, visited, ret, curr);
        return ret;
    }
};
