class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<pair<string, string>> strs2;
        for (string s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            strs2.push_back({t, s});
        }
        sort(strs2.begin(), strs2.end());
        string &cstr = strs2[0].first;
        ret.push_back({strs2[0].second});
        for (int i = 1; i<strs.size(); i++) {
            if (cstr == strs2[i].first) {
                ret[ret.size()-1].push_back(strs2[i].second);
            } else {
                ret.push_back({strs2[i].second});
                cstr = strs2[i].first;
            }
        }
        return ret;
    }
};
