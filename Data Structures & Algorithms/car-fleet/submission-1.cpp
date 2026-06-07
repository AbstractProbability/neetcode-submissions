class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars(position.size());
        for (int i = 0; i<position.size(); i++) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        sort(cars.begin(), cars.end());
        int pd = target-cars[cars.size()-1].first;
        int ps = cars[cars.size()-1].second;
        int total = 1;
        int n = cars.size();
        for (int i = n-1; i>=0; i--) {
            int cd = target-cars[i].first;
            int cs = cars[i].second;
            if (cd*ps > pd*cs) {
                total++;
                pd = cd;
                ps = cs;
            }
        }
        return total;
    }
};
