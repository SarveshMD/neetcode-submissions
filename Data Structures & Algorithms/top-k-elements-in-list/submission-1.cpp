class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    { // BEST: O(n+n+n+k) time
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> frequencies;
        for (int i : nums)
        {
            frequencies[i]++;
        }
        for (auto item : frequencies)
        {
            bucket[item.second].push_back(item.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 1 && k > 0; i--)
        {
            if (!bucket[i].empty())
            {
                for (int num : bucket[i])
                {
                    ans.push_back(num);
                    k--;
                    if (k == 0)
                        break;
                }
            }
        }
        return ans;
    }
};
