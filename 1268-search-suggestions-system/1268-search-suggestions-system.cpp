class TrieNode {
public:
    TrieNode* alphabets[26];
    bool is_word;

    TrieNode() {
        for (TrieNode*& node: alphabets) node = nullptr;
        is_word = false;
    }
};

class Solution {
    TrieNode* root;
    int cnt;
public:
    void FindWord(const TrieNode* const node, vector<vector<string>>& ret, const int& idx, 
                  string prefix) {
        if (cnt >= 3 || !node) return;

        if (node->is_word) {
            cnt++;
            ret[idx].push_back(prefix);
        }

        for (int i=0; i<26; i++) {
            if (cnt >= 3) return;
            
            if (node->alphabets[i]) {
                char tmp = 'a' + i;
                FindWord(node->alphabets[i], ret, idx, prefix+tmp);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode;
        TrieNode* ptr;
        vector<vector<string>> ret(searchWord.size(), vector<string>());

        // construct the trie tree
        for (const string& str: products) {
            ptr = root;
            for (const char& ch: str) {
                if (!ptr->alphabets[ch-'a']) ptr->alphabets[ch-'a'] = new TrieNode;
                ptr = ptr->alphabets[ch-'a'];
            }
            ptr->is_word = true;
        }

        // find suggested products through DFS
        ptr = root;
        string prefix;
        for (int i=0; i<searchWord.size(); i++) {
            if (!ptr) continue;

            cnt = 0;
            prefix += searchWord[i];
            ptr = ptr->alphabets[searchWord[i]-'a'];
            FindWord(ptr, ret, i, prefix);
        }

        return ret;
    }
};