class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";
        for (int i = 0 ; i < s.size();i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                newString.push_back(tolower(s[i]));
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                newString.push_back(tolower(s[i]));
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                newString.push_back(s[i]);
            }
        }
        for (int i = 0, j = newString.size()-1; i <= j; i++ ,j--)
        {
            if (newString[i] != newString[j])return false;
        }
        return true;
    }
};