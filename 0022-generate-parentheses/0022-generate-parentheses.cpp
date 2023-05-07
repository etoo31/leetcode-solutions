class Solution {
private:
    vector<string>ans;
public:
    vector<string> generateParenthesis(int n) {
        getAll(0 , 0 , n , "");
        for (auto x : ans)
            cout << x << endl;
        return ans;
    }
    void getAll(int open , int close , int n , string s)
    {
        if (open == n && close == n)
        {
            ans.push_back(s);
            return;
        }
        if (open < n)
        {
            s.push_back('(');
            getAll(open +1 , close , n , s);
            s.pop_back();
        }
        if (close < open)
        {
            s.push_back(')');
            getAll(open, close+1 , n , s);
            s.pop_back();
        }
        return;
        
    }
};