class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq = priority_queue<int>(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int heaviest = pq.top();
            pq.pop();
            int heaviest2 = pq.top();
            pq.pop();
            heaviest -= heaviest2;
            pq.push(heaviest);
        }
        return pq.top();
    }
};
