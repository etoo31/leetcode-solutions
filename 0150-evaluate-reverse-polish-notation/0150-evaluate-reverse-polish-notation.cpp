class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //cout << stoi(x) << endl;
        int n = tokens.size();
        stack<string>st;
        int res = 0;
        for (int i = 0 ; i < n; i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" )
            {
                int n2 = stoi(st.top());
                st.pop();
                int n1 = stoi(st.top());
                st.pop();
                string ret = DoOperation(n1 ,n2, tokens[i]);
                st.push(ret);
            }
            else st.push(tokens[i]);
            
        }
        return stoi(st.top());
    }
    string DoOperation(int n1 ,int n2, string op)
    {
        if (op == "+")
        {
            return to_string(n1 + n2);
        }
        else if (op == "-")
        {
            return to_string(n1 - n2);
        }
        else if (op == "*")
        {
            return to_string(n1 * n2);
        }
        else
        {
            return to_string(n1 / n2);
        }
        //return "";
        
    }
};