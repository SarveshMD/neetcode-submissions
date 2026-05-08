class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashS, hashT;
        for (char c: s) {
            hashS[c]++;
        }
        for (char c: t) {
            hashT[c]++;
        }
        for (auto item: hashT) {
            if (hashS[item.first] != item.second) return false;
        }
        for (auto item: hashS) {
            if (hashT[item.first] != item.second) return false;
        }
        return true;
    }
};
