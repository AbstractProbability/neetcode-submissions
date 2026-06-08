class MedianFinder {
    priority_queue<int> small, large;
public:
    MedianFinder() {
        this->small = priority_queue<int>();
        this->large = priority_queue<int>();
    }
    
    void addNum(int num) {
        if (small.empty()) {
            small.push(num);
            return;
        }

        if (num < small.top())   { small.push(num); }
        else                                        { large.push(-num); }
        
        while (small.size() > large.size()+1) {
            int top = small.top();
            small.pop();
            large.push(-top);
        }
        while (small.size()+1 < large.size()) {
            int top = large.top();
            large.pop();
            small.push(-top);
        }
    }
    
    double findMedian() {
        if (small.size() == large.size())           { return (double)(small.top() - large.top())/(double)2; }
        else if (small.size() < large.size())   { return -large.top(); }
        else                                                                        { return small.top(); }
    }
};
