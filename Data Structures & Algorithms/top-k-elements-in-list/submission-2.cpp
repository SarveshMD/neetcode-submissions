class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    { // BEST: O(n+n+n+k) time
        unordered_map<int, int> hashmap;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            hashmap[nums[i]]++;
        }
        vector<vector<int>> buckets(n+1);
        for (auto& item: hashmap) {
            buckets[item.second].push_back(item.first);
        }
        vector<int> sol;
        for (int i=n; i>=0 && k > 0; i--) {
            if (buckets[i].empty()) continue;
            for (int j=0; j<buckets[i].size() && k > 0; j++) {
                sol.push_back(buckets[i][j]);
                k--;
            }
        }
        return sol;
    }
};
