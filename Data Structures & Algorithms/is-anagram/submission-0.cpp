class Solution {
public:
    void populate_freq(vector<int> &freq, string s) {
        for (int i = 0; i<s.length(); i++) {
            freq[s[i]-'a']++;
        }
    }
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freqs(26, 0), freqt(26, 0);
        populate_freq(freqs, s);
        populate_freq(freqt, t);

        for (int i = 0; i<26; i++) {
            if (freqs[i] != freqt[i]) {
                return false;
            }
        }
        return true;
    }
};
