class Solution {
public:
    vector<vector<bool>>visted;
    int r, c;
    bool exist(vector<vector<char>>& board, string word) {
        visted = vector<vector<bool>>(6 , vector<bool>(6));
        r = board.size();
        c = board[0].size();
        for (int i = 0 ; i < r; i++)
        {
            for (int j = 0 ; j < c; j++)
            {
                if (word[0] == board[i][j])
                {
                   bool isTrue = solve(i , j , 0, board , word );
                    if (isTrue)return true;
                }
            }
        }
        return false;
    }
    bool valid(int i , int j , int index, vector<vector<char>>& board , string& word)
    {
        return i >= 0 && i < r && j >= 0 && j < c && !visted[i][j] && board[i][j] == word[index];
    }
    bool solve(int i , int j , int index, vector<vector<char>>& board , string& word)
    {
        if (index == word.size())return true;
        if (!valid(i , j , index, board , word))
            return false;
        
        visted[i][j] = true;
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        for (int h = 0; h < 4; h++)
        {
            int x = i + dx[h];
            int y = j + dy[h];
            bool isTrue = solve(x , y , index+1 , board , word);
            if (isTrue)return true;
        }
        visted[i][j] = false;
        return false;
    }
};