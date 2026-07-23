class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charmap(26, 0);
        for (char c: s) {
            charmap[c - 'a']++;
        }
        for (char c: t) {
            charmap[c - 'a']--;
        }
        for (int i=0; i<26; i++) {
            if (charmap[i] != 0) return false;
        }
        return true;
    }
};
