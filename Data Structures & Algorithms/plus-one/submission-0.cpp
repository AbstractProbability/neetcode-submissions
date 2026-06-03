class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size()-1; i>=0; i--) {
            int tot = carry+digits[i];
            digits[i] = tot%10;
            carry = tot/10;
        }
        if (carry) {
            vector<int> ret(digits.size()+1, 0);
            ret[0] = 1;
            return ret;
        }
        return digits;
    }
};
