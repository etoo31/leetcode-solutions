class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n , 0);
        stack<pair<int , int>>st;
        for (int i = 0 ; i < n; i++)
        {
            if (!i)
            {
                st.push({temperatures[i] , i});
                continue;
            }
            while(!st.empty() && st.top().first < temperatures[i])
            {
                auto temp =  st.top();
                st.pop();
                ans[temp.second] = i-temp.second;
            }
            st.push({temperatures[i] , i});
        }
        return ans;
    }
};