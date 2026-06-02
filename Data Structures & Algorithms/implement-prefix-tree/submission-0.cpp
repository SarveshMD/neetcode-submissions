class TrieNode {
public:
    bool endOfWord = false;
    unordered_map<char, TrieNode*> children;
};

class PrefixTree {
public:
    TrieNode* root = new TrieNode();
    PrefixTree() {
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (!curr->children[c])
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (!curr->children[c]) return false;
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix) {
            if (!curr->children[c]) return false;
            curr = curr->children[c];
        }
        return true;
    }
};
