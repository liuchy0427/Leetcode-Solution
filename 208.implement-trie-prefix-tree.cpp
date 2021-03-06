/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
private:
    map<char, Trie*> next = {};
    bool isWord = false;
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;

        for(char ch:word){
            if(!node->next.count(ch))
                node->next[ch] = new Trie();
            
            node = node->next[ch];
        }

        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;

        for(char ch:word){
            if(!node->next.count(ch))   return false;
            node = node->next[ch];
        }

        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;

        for(char ch:prefix){
            if(!node->next.count(ch))   return false;
            node = node->next[ch];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

