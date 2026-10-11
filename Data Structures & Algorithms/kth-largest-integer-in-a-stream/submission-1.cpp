class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        if (pq.size() == k && pq.top() <= val) {
            pq.pop();
            pq.push(val);
        }
        if (pq.size() < k) {
            pq.push(val);
        }
        return pq.top();
    }
};
