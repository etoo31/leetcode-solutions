class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>>st;
        int ans = 0;
        for (int i = 0 ; i < n; i++)
        {
            int index = i;
            while(!st.empty() && heights[i] < st.top().first)
            {
                auto temp = st.top();
                st.pop();
                index = temp.second;
                ans = max(ans , temp.first * (i - temp.second));
            }
            st.push({heights[i] , index});
        }
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();
            ans = max(ans , temp.first * (n - temp.second));   
        }
        return ans;
    }
};