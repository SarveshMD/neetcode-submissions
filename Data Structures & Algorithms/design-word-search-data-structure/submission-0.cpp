class TrieNode {
public:
    bool endOfWord = false;
    unordered_map<char, TrieNode*> children;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (!curr->children[c]) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool searchSubtrie(string& word, TrieNode* subtrie, int start) {
        TrieNode* curr = subtrie;
        for (int i=start; i<word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto pr: curr->children) {
                    if (!pr.second) continue;
                    if (searchSubtrie(word, pr.second, i+1)) return true;
                }
                return false;
            }
            else if (!curr->children[c]) return false;
            else curr = curr->children[c];
        }
        return curr->endOfWord;
    }

    bool search(string word) {
        TrieNode* curr = root;
        return searchSubtrie(word, curr, 0);
    }
};
