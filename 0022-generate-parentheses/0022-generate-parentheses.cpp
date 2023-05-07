class Solution {
private:
    vector<string>ans;
    string s;
    int size;
public:
    vector<string> generateParenthesis(int n) {
        s = "";
        size = n;
        getAll(0 , 0);
        return ans;
    }
    void getAll(int open , int close)
    {
        if (open == size && close == size)
        {
            ans.push_back(s);
            return;
        }
        if (open < size)
        {
            s.push_back('(');
            getAll(open +1 , close);
            s.pop_back();
        }
        if (close < open)
        {
            s.push_back(')');
            getAll(open, close+1);
            s.pop_back();
        }
        return;
        
    }
};