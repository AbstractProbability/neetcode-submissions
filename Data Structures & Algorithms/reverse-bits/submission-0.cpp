class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (uint32_t i = 0; i<32; i++) {
            uint32_t bit = ((1u<<i)&n)>>i;
            ret |= (bit<<(32-i-1));
        }
        return ret;
    }
};
