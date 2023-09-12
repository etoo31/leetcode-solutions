class Solution {
public:
    vector<bool>rows;
    vector<bool> cols;
    
    vector<string>grid;
    
    vector<pair<int,int>>q;
    
    vector<vector<string>>ans;
    
    vector<vector<string>> solveNQueens(int n) {
        
        preProcess(n);
        solve(0 , n);
        /*for (auto g : ans){
            for (auto x : g)
                cout << x << endl;
            cout << "\n\n";
        }*/
        return ans;
    }
    void preProcess(int n)
    {
        string s = "";
        for (int i = 0 ; i < n; i++)
            s.push_back('.');
        for (int i = 0 ; i < n; i++)
            grid.push_back(s);
        for (int i = 0 ; i < n; i++)
        {
            rows.push_back(true);
            cols.push_back(true);
        }
    }
    void solve(int r , int & n)
    {
        if (r == n)
        {
            ans.push_back(grid);
            return;
        }
        for (int c = 0 ; c < n; c++)
        {
            if (isValid(r , c))
            {
                rows[r] = false;
                cols[c] = false;
                q.push_back({r,c});
                grid[r][c] = 'Q';
                
                solve(r+1 , n);
                
                rows[r] = true;
                cols[c] = true;
                q.pop_back();
                grid[r][c] = '.';
            }
        }
    }
    bool isValid(int r , int c)
    {
        bool ret = rows[r] & cols[c];
        for (int i = 0 ; i < q.size(); i++)
        {
            if (abs(r - q[i].first) == abs(c - q[i].second) == 1)
                return false;
        }
        return ret;
    }
};