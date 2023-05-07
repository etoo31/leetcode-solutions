class Solution {
private:
    vector<string>ans;
    string s;
public:
    vector<string> generateParenthesis(int n) {
        s = "";
        getAll(0 , 0 , n );
        return ans;
    }
    void getAll(int open , int close , int n)
    {
        if (open == n && close == n)
        {
            ans.push_back(s);
            return;
        }
        if (open < n)
        {
            s.push_back('(');
            getAll(open +1 , close , n);
            s.pop_back();
        }
        if (close < open)
        {
            s.push_back(')');
            getAll(open, close+1 , n);
            s.pop_back();
        }
        return;
        
    }
};