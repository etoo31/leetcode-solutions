class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())return false;
        unordered_map<char , int>smp , tmp;
        for (int i = 0 ; i < s.size(); i++)smp[s[i]]++;
        for (int i = 0 ; i < t.size(); i++)tmp[t[i]]++;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (tmp[s[i]] != smp[s[i]])return false;
        }
        return true;
    }
};