class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkSqaures(board);
        
    }
    bool checkRows(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<bool>v(10 , 0);
            for (int j = 0; j < 9; j++)
            {
                int n = toInt(board[i][j]);
                if (n == -1)
                    continue;
                if (v[n])
                    return false;
                v[n] = true;
            }
        }
        return true;
    }
    bool checkCols(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<bool>v(10 , 0);
            for (int j = 0; j < 9; j++)
            {
                int n = toInt(board[j][i]);
                if (n == -1)
                    continue;
                if (v[n]){
                    cout << i << " "<<  j << endl;
                    cout << n  << " : " << v[n]<< endl;
                    
                    return false;
                }
                v[n] = true;
            }
        }
        return true;
    }
    bool checkSqaures(vector<vector<char>>& board)
    {
        for (int i = 1; i < 9; i+= 3)
        {
            int r[] = {0 , 0 , 0,-1,-1,-1,1, 1,1};
            int c[] = {0 , -1, 1, 0,-1, 1,0,-1,1};
            for (int j = 1; j < 9; j+= 3)
            {
                vector<bool>v(10 , 0);
                for (int x = 0; x < 9; x++)
                {
                    int nrow = r[x]+i;
                    int ncol = c[x]+j;
                    //cout << nrow << " " << ncol << endl;
                    int n = toInt(board[nrow][ncol]);
                    if (n == -1)
                        continue;
                    if (v[n])
                        return false;
                    v[n] = true;
                }
                //cout << " ------------------------------------------------------------\n";
            }
            
        }
        return true;
    }
    int toInt(char s)
    {
        if (s == '.')
            return -1;
        else return (int)(s- '0');
    }
};