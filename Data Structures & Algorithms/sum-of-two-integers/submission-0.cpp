class Solution {
public:
    int getSum(int a, int b) {
        int mask = 1;
        int carry = 0;
        int ret = 0;
        for (int i = 0; i<32; i++) {
            int a1 = ((mask<<i)&a)>>i;
            int b1 = ((mask<<i)&b)>>i;
            ret |= (a1^b1^carry)<<i;
            carry = (a1&b1) | (a1&carry) | (b1&carry);
        }
        return ret;
    }
};
