class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> ans(n,0);
        stack<pair<int,int>>st;
        for (int i = 0 ; i < n; i++)
        {
            if (i)
            {
                solve(st ,temperatures[i] , ans  , i);
            }
            st.push({temperatures[i] , i});
        }
        

        return ans;
    }
    void solve(stack<pair<int,int>>&st , int cur , vector<int>&ans , int i)
    {
        
        while (!st.empty()) {
        auto x = st.top();
        if (cur <= x.first)
            break;   
        ans[x.second] = i-x.second;  
        st.pop();
        }
        
    }
};