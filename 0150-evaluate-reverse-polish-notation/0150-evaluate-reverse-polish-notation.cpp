class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<string>st;
        for (int i = 0 ; i < n;i++)
        {
            if (tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "/")
            {
                //cout << "i'm in" << endl;
                st.push(tokens[i]);
            }
            else 
            {
                string x2 = st.top();
                st.pop();
                string x1 = st.top();
                st.pop();
                string temp = makeCalulations(x1 , x2 , tokens[i]);
                //cout << x1 << " " << tokens[i] << " " << x2 << " = " << temp << endl;
                st.push(temp);
            }
        }
        return getNumber(st.top());
    }
    string makeCalulations(string x1 , string x2 , string operation)
    {
        //cout << "hello " << endl;
        int num1 = getNumber(x1);
        int num2 = getNumber(x2);
        
        if (operation == "+")
        {
            
            return to_string(num1 + num2);
        }
        else if (operation == "-")
        {
           
            return to_string(num1 - num2);
        }
        else if (operation == "*")
        {
            
            return to_string(num1 * num2);
        }
        else if (operation == "/")
        {
            
            return to_string(num1 / num2);
        }
        return to_string(-1);
    }
    int getNumber(string x)
    {
        long long ret = 0;
        int negative = 1;
        for (int i = 0 ; i < x.size(); i++)
        {
            if (x[i] == '-')
            {
                negative = -1;
                continue;
            }
            ret = ret * 10 + (x[i] - '0');
        }
        return ret*negative;
    }
};