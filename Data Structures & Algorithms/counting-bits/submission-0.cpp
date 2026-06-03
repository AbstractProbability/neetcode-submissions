class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        for (int i = 0; i<=n; i++) {
            bits[i] = popcount((uint32_t)i);
        }
        return bits;
    }
};
