class TrieNode{
public:
    char val;
    map<char,TrieNode *>mp;
    bool isLast;
    TrieNode(char v)
    {
        val = v;
        isLast = false;
    }
    void addWord(string word)
    {
        TrieNode * node = this;
        for (int i = 0 ; i < word.size(); i++)
        {
            if (!node->mp[word[i]])
            {
                node->mp[word[i]] = new TrieNode(word[i]);
            }
            node = node->mp[word[i]];
        }
        node->isLast = true;
    }
    
};
class Solution {
public:
    bool visted[12][12];
    set<string>st;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        vector<string>ans;
        TrieNode * root = new TrieNode(' ');
        for (int i = 0 ; i < words.size(); i++)
            root->addWord(words[i]);
     
        
        for (int i = 0 ; i < board.size(); i++)
            for (int j = 0 ; j < board[i].size(); j++)
                dfs(root,i,j,board,"");
        for (auto s : st)
            ans.push_back(s);
        return ans;
    }
    bool isValid(int i , int j , vector<vector<char>>& board)
    {
            return i >= 0 && i < board.size() && j >= 0 && j < board[i].size() &&
                !visted[i][j];
    }
    void dfs(TrieNode* curr, int i , int j , vector<vector<char>>& board, string word)
    {
        if (!isValid(i , j , board))return;
        if (!curr->mp[board[i][j]])return;
        
        word += board[i][j];
        TrieNode * node = curr->mp[board[i][j]];
        if (node->isLast){
            st.insert(word);
            //cout << word << endl;
        }
        
        //cout << i << " " << j << " " << "true" << endl;
        visted[i][j] = true;
        int dx[] = {0 , 0 , 1 , -1};
        int dy[] = {1 ,-1 , 0 ,  0};
        for (int h = 0; h < 4; h++)
        {
            int x = dx[h] + i;
            int y = dy[h] + j;
            dfs(node, x , y, board,word);
        }
        //cout << i << " " << j << " " << "false" << endl; 
        visted[i][j] = false;
    }
};