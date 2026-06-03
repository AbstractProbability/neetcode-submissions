class KthLargest {
    int k;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->pq.push(0);
        this->pq = priority_queue<int>();
        for (int i = 0; i<nums.size(); i++) {
            this->add(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(-val);
        if (pq.size() > k) { pq.pop(); }
        return -pq.top();
    }
};
