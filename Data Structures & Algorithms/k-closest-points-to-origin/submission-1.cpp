class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        priority_queue<pair<int, pair<int,int>>> pq;
        for (int i = 0; i<k; i++) {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],
                            {points[i][0], points[i][1]}});
        }
        for (int i = k; i<points.size(); i++) {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],
                            {points[i][0], points[i][1]}});
            pq.pop();
        }
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ret.push_back({top.second.first, top.second.second});
        }
        return ret;
    }
};
