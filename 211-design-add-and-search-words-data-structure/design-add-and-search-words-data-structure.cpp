struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node) {
        links[ch-'a'] = node;
    }
    Node *get(char ch) {
        return links[ch-'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool getEnd() {
        return flag;
    }
};
class Trie{
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    Node *getRoot() {
        return root;
    }
};

class WordDictionary {
public:
    Trie trie;
    bool dfs(string word, int idx, Node *node) {
        if(idx == word.size()) return node->getEnd();
        char ch = word[idx];
        if(ch == '.') {
            for(char c='a'; c<='z'; c++) {
                if(node->containsKey(c)) {
                    if(dfs(word, idx+1, node->get(c))) return true;
                }
            }
        } else {
            if(!node->containsKey(ch)) return false;
            return dfs(word, idx+1, node->get(ch));
        }
        return false;
    }
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return dfs(word, 0, trie.getRoot());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */