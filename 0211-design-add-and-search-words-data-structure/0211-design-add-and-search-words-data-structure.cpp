#define GET_INDEX(ch) (ch) == '.' ? 26: (ch) - 'a'

class CharNode {
    CharNode *charnodes_[26];
    bool is_end_;
public:
    CharNode() {
        for (CharNode *&cn: charnodes_) 
            cn = nullptr;

        is_end_ = false;
    }

    CharNode *findChar(const char search_ch) {
        return charnodes_[GET_INDEX(search_ch)];
    }

    CharNode *addChar(const char add_ch) {
        unsigned int idx = GET_INDEX(add_ch);

        if (!charnodes_[idx]) charnodes_[idx] = new CharNode;
        
        return charnodes_[idx];
    }

    void setEnd() {
        is_end_ = true;
    }

    bool isEnd() {
        return is_end_;
    }

    ~CharNode() {
        for (CharNode *&cn: charnodes_) {
            if (cn) {
                delete cn;
                cn = nullptr;
            }
        }
    }
};

class WordDictionary {
    CharNode *head_;
public:
    WordDictionary() {
        head_ = new CharNode;
    }
    
    void addWord(string word) {
        CharNode *node = head_;
        int last_idx = word.length()-1;

        for (int idx=0; idx<=last_idx; idx++) 
            node = node->addChar(word[idx]);
        node->setEnd();
    }
    
    bool search(string word) {
        CharNode *node = head_;
        deque<CharNode *> q;
        int search_nodes_cnt = 1;

        q.push_back(node);
        for (const char ch: word) {
            unsigned int next_round_cnt = 0;

            if (GET_INDEX(ch) == 26) {
                while (search_nodes_cnt--) {    
                    node = q.front();
                    q.pop_front();

                    // record each possible path
                    for (int i=0; i<26; i++) {
                        CharNode *search_node = node->findChar('a'+i);

                        if (search_node) {
                            q.push_back(search_node);
                            next_round_cnt++;
                        }
                    }
                }
            } else {
                while (search_nodes_cnt--) {    
                    CharNode *search_node = q.front()->findChar(ch);
                    q.pop_front();

                    if (search_node) {
                        q.push_back(search_node);
                        next_round_cnt++;
                    } 
                }

                if (q.empty()) return false;
            }

            search_nodes_cnt = next_round_cnt;
        }

        // check whether the possible paths include the end of the word
        while (!q.empty()) {
            if (q.front()->isEnd()) return true;

            q.pop_front();
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */