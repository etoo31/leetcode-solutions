class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1f[26] = {};
        int s2f[26] = {};
        for (int i = 0; i < s1.size(); i++)
        {
            s1f[s1[i]-'a']++;
        }
        int j = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            s2f[s2[i] - 'a']++;
            if (i-j+1 == s1.size())
            {
                bool isPermuatation = true;
                for (int x = 0; x < 26; x++)
                {
                    if (s1f[x] != s2f[x])
                        isPermuatation = false;
                }
                if (isPermuatation)return true;
                s2f[s2[j]-'a']--;
                j++;
            }
        }
        return false;
        
        
    }
};