class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> solMap;
        for (string &str: strs) {
            vector<int> wordMap(26, 0);
            for (char& c: str) {
                wordMap[c - 'a']++;
            }
            solMap[wordMap].push_back(str);
        }
        vector<vector<string>> sol;
        for (auto &pr: solMap) {
            sol.push_back(pr.second);
        }
        return sol;
    }
};
