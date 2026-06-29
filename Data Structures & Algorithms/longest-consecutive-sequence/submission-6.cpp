class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        // set<int> st;
        // for (auto num: nums) {
        //     st.insert(num);
        // }

        // int mlen = 0;
        // for (int i = 0; i<nums.size(); i++) {
        //     if (st.find(nums[i]-1) == st.end()) {
        //         int num = nums[i];
        //         int clen = 0;
        //         while (st.find(num) != st.end()) {
        //             clen++; num++;
        //         }
        //         mlen = max(clen, mlen);
        //     }
        // }
        sort(nums.begin(), nums.end());
        int mlen = 1, clen = 1,  prev = nums[0];
        for (int i = 1; i<nums.size(); i++) {
            if (nums[i] == prev+1) {
                clen++;
            } else if (nums[i] > prev+1) {
                clen = 1;
            }
            prev = nums[i];
            mlen = max(mlen, clen);
        }
        return mlen;
    }
};
