class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (st.size() == 0)return false;
                
                char top = st.top();
                if (s[i] == ']' && top != '[')return false;
                else if (s[i] == ')' && top != '(')return false;
                else if (s[i] == '}' && top != '{')return false;
                st.pop();
            }   
        }
        return (!st.size());
    }
};