class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (auto num: nums) {
            st.insert(num);
        }

        int mlen = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (st.find(nums[i]-1) == st.end()) {
                int num = nums[i];
                int clen = 0;
                while (st.find(num) != st.end()) {
                    clen++; num++;
                }
                mlen = max(clen, mlen);
            }
        }
        return mlen;
    }
};
