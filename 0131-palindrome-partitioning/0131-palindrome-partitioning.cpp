class Solution {
public:
    vector<vector<string>>ans;
    vector<string>part;
    vector<vector<string>> partition(string s) {
        dfs(0 , s);
        return ans;
    }
    void dfs(int i , string& s)
    {
        if (i == s.size())
        {
            ans.push_back(part);
            return;
        }
        string p = "";
        for (int j = i; j < s.size(); j++)
        {
            p += s[j];
            if (isPlaindrom(p))
            {
                part.push_back(p);
                dfs(j+1 , s);
                part.pop_back();
            }
        }
        return;
    }
    bool isPlaindrom(string s)
    {
        int i = 0;
        int j = s.size()-1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};