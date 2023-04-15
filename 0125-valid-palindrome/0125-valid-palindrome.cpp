class Solution {
public:
    bool isPalindrome(string s) {
    
        int n = s.size();
        
        int i = 0 , j = n-1;
        bool palindrome = true;
        while (i < j)
        {
            while ( i < n && (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <='Z') && !(s[i] >= '0' && s[i] <= '9')))
                i++;
            while ( j >= 0 &&(!(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <='Z') && !(s[j] >= '0' && s[j] <= '9')))
                j--;
            //cout << i << j << endl;
            if (i < j)
            {
                s[i] = tolower(s[i]);
                s[j] = tolower(s[j]);
                //cout << s[i] << " " << s[j] << endl;
                if (s[i] != s[j])
                    palindrome = false;
            }
            i++;
            j--;
        }
        return palindrome;
    }
};