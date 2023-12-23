class TrieNode {
public:
    TrieNode* alphabets[26];
    bool is_word;

    TrieNode() {
        for (TrieNode*& tn: alphabets) tn = nullptr;
        is_word = false;
    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;

        for (const char& ch: word) {
            if (!p->alphabets[ch-'a']) {
                p->alphabets[ch-'a'] = new TrieNode();
            }
            p = p->alphabets[ch-'a'];
        }
        p->is_word = true;
    }
    
    bool search(string word, bool is_search=true) {
        TrieNode* p = root;

        for (const char& ch: word) {
            if (!p->alphabets[ch-'a'])
                return false;
            p = p->alphabets[ch-'a'];
        }

        if (is_search)
            return p->is_word;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */