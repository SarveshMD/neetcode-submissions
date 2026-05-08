class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequencies;
        for (int i: nums) {
            frequencies[i]++;
        }
        vector<pair<int, int>> fvec(frequencies.begin(), frequencies.end());
        sort(fvec.begin(), fvec.end(), [](const pair<int, int>& a, const pair<int,int>& b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i=0; i<k; i++) {
            ans.push_back(fvec[i].first);
        }
        return ans;
    }
};
