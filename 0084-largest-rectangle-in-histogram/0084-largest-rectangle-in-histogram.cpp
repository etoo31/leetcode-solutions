class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int , int>>st;
        int maxArea = 0;
        for (int i = 0 ; i < n; i++)
        {
            if (i == 0)
            {
                st.push({heights[i] , i});
                continue;
            }
            int lowIndex = i;
            while (!st.empty() && st.top().first > heights[i])
            {
                pair<int,int> temp = st.top();
                st.pop();
                maxArea = max(maxArea , (i-temp.second) * temp.first);
                lowIndex = temp.second;
            }
            if (!st.empty() && st.top().first == heights[i])
            {
                continue;
            }
            st.push({heights[i] , lowIndex});
        }
        while (!st.empty())
            {
                pair<int,int> temp = st.top();
                st.pop();
                maxArea = max(maxArea , (n-temp.second) * temp.first);
            }
        return maxArea;
    }
};