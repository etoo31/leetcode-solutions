class Solution {
public:
    map<char , string>mp;
    vector<string>ans;
    string s;
    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(0 , digits);
        return ans;
    }
    void solve(int i , string & digits)
    {
        if (i == digits.size())
        {
            if (s.size())
                ans.push_back(s);
            return;
        }
        string x  = mp[digits[i]];
        for (int j = 0; j < x.size(); j++)
        {
            s.push_back(x[j]);
            solve(i+1 , digits);
            s.pop_back();
        }
        return;
    }
};