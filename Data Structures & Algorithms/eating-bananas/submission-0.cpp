class Solution {
public:
    bool checkfinish(vector<int>& piles, int speed, int time)
    {
        int total = 0;
        for (int i = 0; i<piles.size(); i++) {
            total += piles[i]/speed;
            total += (piles[i]%speed != 0); 
        }
        return total <= time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mspeed = INT_MIN;
        for (int i = 0; i<piles.size(); i++) { mspeed = max(mspeed, piles[i]); }
        int l = 1, r = mspeed;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (checkfinish(piles, m, h)) { r = m-1; }
            else { l = m+1; }
        }
        if (checkfinish(piles, l, h)) { return l; }
        else { return r; }
    }
};
