class Solution {
public:
    bool is_alpha_num(char c) {
        if (c >= 'A' && c <= 'Z'
                || c >= 'a' && c <= 'z'
                || c >= '0' && c <= '9'
        ) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while (l < r) {
            while (l < n && !is_alpha_num(s[l])) { l++; }
            while (r >= 0 && !is_alpha_num(s[r])) { r--; }
            if (tolower(s[l]) != tolower(s[r])) { return false; }
            l++; r--;
        }
        return true;
    }
};
