class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hashS, hashT;
        for (int i=0; i<s.size(); i++) {
            hashS[s[i]]++;
            hashT[t[i]]++;
        }
        for (auto item: hashS) {
            if (hashT[item.first] != item.second) return false;
        }
        return true;
    }
};
