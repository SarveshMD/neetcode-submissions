class MedianFinder {
public:
    priority_queue<int> small_heap;
    priority_queue<int, vector<int>, greater<int>> large_heap;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        small_heap.push(num);
        int val = small_heap.top();
        small_heap.pop();
        large_heap.push(val);
        int n_left = small_heap.size();
        int n_right = large_heap.size();
        if (n_left > n_right + 1) {
            int val = small_heap.top();
            small_heap.pop();
            large_heap.push(val);
        }
        else if (n_right > n_left + 1) {
            int val = large_heap.top();
            large_heap.pop();
            small_heap.push(val);
        }
    }
    
    double findMedian() {
        int n_small = small_heap.size();
        int n_large = large_heap.size();
        int n = n_small + n_large;
        if (n%2 == 0) {
            return (small_heap.top() + large_heap.top())/2.0;
        }
        else {
            if (n_small > n_large) {
                return small_heap.top();
            }
            else {
                return large_heap.top();
            }
        }
    }
};
