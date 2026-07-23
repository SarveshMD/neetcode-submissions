class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> master_map;
        for (string& str: strs) {
            vector<int> hashmap(26, 0);
            for (char c: str) {
                hashmap[c - 'a']++;
            }
            master_map[hashmap].push_back(str);
        }
        vector<vector<string>> sol;
        for (auto& pr: master_map) {
            sol.push_back(pr.second);
        }
        return sol;        
    }
};
