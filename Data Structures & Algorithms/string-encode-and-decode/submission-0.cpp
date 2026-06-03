class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for (int i = 0; i<strs.size(); i++) {
            for (int j = 0; j<strs[i].length(); j++) {
                string append = "|";
                append += strs[i][j];
                ret += append;
            }
            string dot = ".";
            ret += dot;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        
        bool pipe = false;
        string curr = "";
        for (int i = 0; i<s.length(); i++) {
            if (pipe) {
                curr += s[i];
                pipe = false;
                continue;
            }
            if (s[i] == '|') {
                pipe = true;
            } else if (s[i] == '.') {
                ret.push_back(curr);
                curr = "";
            }
        }
        return ret;
    }
};
