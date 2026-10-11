class KthLargest {
public:
    int k;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            pq.push(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> popped;
        for (int i=0; i<k-1; i++) {
            int tmp = pq.top();
            popped.push_back(tmp);
            pq.pop();
        }
        int res = pq.top();
        for (int item: popped) {
            pq.push(item);
        }
        return res;
    }
};
