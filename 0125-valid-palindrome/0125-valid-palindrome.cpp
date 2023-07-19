class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for (int i = 0 ;i  < s.size(); i++)
        {
            if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9'))
                continue;
            st += tolower(s[i]);
        }
        //cout << st << endl;
        int i = 0 , j = st.size()-1;
        while (i <= j)
        {
            if(st[i] != st[j])return false;
            i++;
            j--;
        }
        return 1;
    }
};