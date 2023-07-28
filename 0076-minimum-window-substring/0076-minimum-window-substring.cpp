class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char , int>tmp;
        unordered_map<char , int>smp;
        int left = 0, right = 1e9;
        for (int i = 0 ; i < n; i++)
        {
            tmp[t[i]]++;
        }
        int j = 0;
        int have = 0 , need = n;
        for (int i = 0 ; i < m; i++)
        {
            smp[s[i]]++;
            if (smp[s[i]] <= tmp[s[i]])
                have++;
            while(j <= i && smp[s[j]] > tmp[s[j]])
            {
                smp[s[j]]--;
                j++;
            }
            if (have == need)
            {
                if (right - left > i - j)
                {
                    right = i;
                    left = j;
                }
            }
        }
        string ret = "";
        if (right - left == 1e9)return ret;
        for (int i = left; i <= right; i++)
        {
            ret.push_back(s[i]); 
        }
        return ret;
    }
};