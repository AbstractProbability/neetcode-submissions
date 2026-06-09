class Solution {
public:
    void recurse(vector<string> &ret, string &str, int n, int nopen, int nclose)
    {
        if (nopen == 0 && nclose == 0) {
            ret.push_back(str);
            return;
        }

        if (nopen) {
            str += '(';
            recurse(ret, str, n, nopen-1, nclose);
            str.pop_back();
        }
        int clorec = (n-nopen) - (n-nclose);
        if (clorec > 0) {
            // recurse by adding a ')'
            str += ')';
            recurse(ret, str, n, nopen, nclose-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string str;
        recurse(ret, str, n, n, n);
        return ret;
    }
};
