class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        bool ans = true;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' )
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.size() && st.top() == '(')
                {
                    st.pop();
                }
                else 
                {
                    ans = false;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                if (st.size() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (st.size() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
  
    }
        if (st.size())
            ans = false;
        return ans;
    }
};