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
class WordDictionary {
public:
    TrieNode *node;
public:
    WordDictionary() {
     node = new TrieNode();   
    }
    
    void addWord(string word) {
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
        TrieNode *curr = node;
        return helpSearch(curr , word , 0);
    }
    bool helpSearch(TrieNode * curr , string word , int i)
    {
        if (i == word.size() && curr->isLast)return true;
        else if (i == word.size())return false;
        
        if (word[i] == '.')
        {
            for (char j = 'a'; j <='z'; j++)
            {
                if (curr->mp[j]){
                    bool found = helpSearch(curr->mp[j] , word , i+1);
                    if (found)return true;
                }
            }
        }
        else 
        {
            if (curr->mp[word[i]])
                return helpSearch(curr->mp[word[i]] , word , i+1);
            else return false;
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