class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> solMap;
        for (string &str : strs)
        {
            vector<int> hashmap(26, 0);
            for (char c : str)
            {
                hashmap[c - 'a']++;
            }
            solMap[hashmap].push_back(str);
        }
        vector<vector<string>> answer;
        for (auto &pr : solMap)
        {
            answer.push_back(pr.second);
        }
        return answer;
    }
};
