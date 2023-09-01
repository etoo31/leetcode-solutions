class TrieNode{
public:
    char val;
    map<char,TrieNode *>mp;
    bool isLast;
    TrieNode()
    {
        val = ' ';
        isLast = false;
    }
    TrieNode(char v)
    {
        val = v;
        isLast = false;
    }
};
class Trie {
public:
    TrieNode * node;
public:
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * curr = node;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->mp[word[i]])
            {
                curr->mp[word[i]] = new TrieNode(word[i]);
            }
            curr = curr->mp[word[i]];
        }
        curr->isLast = true;
    }
    
    bool search(string word) {
        TrieNode * curr = node;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->mp[word[i]])
            {
                return false;
            }
            curr = curr->mp[word[i]];
        }
        if (!curr->isLast)
            return false;
        else return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode * curr = node;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!curr->mp[prefix[i]])
            {
                return false;
            }
            curr = curr->mp[prefix[i]];
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