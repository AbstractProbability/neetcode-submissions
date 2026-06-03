class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smax = -1, pmax = 0;
        int n = prices.size();
        for (int i = n-1; i>=0; i--) {
            smax = max(smax, prices[i]);
            pmax = max(pmax, smax-prices[i]);
        }
        return pmax;
    }
};
