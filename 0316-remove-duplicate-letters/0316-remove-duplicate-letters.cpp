class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {};
        bool visited[26] = {};
        stack<char>st;
        for (int i = 0 ; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            while (!st.empty() && s[i] < st.top() && !visited[index] && freq[st.top()-'a'])
            {
                char c = st.top();
                visited[st.top()-'a'] = false;
                st.pop();
            }
            if (!visited[index]){
                st.push(s[i]);
                visited[index] = true;
                freq[index]--;
            }
            else
                freq[index]--;
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};