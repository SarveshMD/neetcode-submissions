class Solution {
public:
    bool dfs(char c, unordered_map<char, vector<char>>& adj, unordered_map<char, bool>& visit, vector<char>& res) {
        if (visit.contains(c)) {
            return visit[c];
        }
        visit[c] = true;
        for (char nei: adj[c]) {
            if (dfs(nei, adj, visit, res)) return true;
        }
        visit[c] = false;
        res.push_back(c);
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        for (string& word: words) {
            for (char& c: word) {
                adj[c];
            }
        }
        for (int i=0; i<words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int minLength = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && 
            w1.substr(0, minLength) == w2.substr(0, minLength)) {
                return "";
            }
            for (int j=0; j<minLength; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        
        unordered_map<char, bool> visit;
        vector<char> res;
        for (auto item: adj) {
            if (dfs(item.first, adj, visit, res)) return "";
        }
        int result_size = res.size();
        string result = "";
        for (int i=result_size-1; i>=0; i--) {
            result += res[i];
        }
        return result;
    }
};
