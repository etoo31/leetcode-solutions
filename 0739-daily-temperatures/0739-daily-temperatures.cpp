class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n , 0);
        stack<pair<int,int>>st;
        for (int i = 0 ; i < n; i++)
        {
            int temp = temperatures[i];
            while (!st.empty() && temp > st.top().first)
            {
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp , i});
        }
        return ans;
    
    }
};