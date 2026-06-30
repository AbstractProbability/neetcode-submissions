class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> freq(128, false);
        int lptr = -1, mlen = 0;
        for (int rptr = 0; rptr<s.length(); rptr++) {
            while (freq[s[rptr]]) {
                lptr++;
                freq[s[lptr]] = false;
            }
            freq[s[rptr]] = true;
            mlen = max(mlen, rptr-lptr);
        }
        return mlen;
    }
};
