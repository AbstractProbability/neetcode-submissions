class Solution {
public:
    int reverse(int x) {
        long long x2 = x, ans = 0;
        while (x2) {
            int ones = x2%10;
            ans = ans*10+ones;
            x2 /= 10;
        }
        int ans2 = (int) ans;
        if (ans2 == ans) {
            return ans2;
        }
        return 0;
    }
};
