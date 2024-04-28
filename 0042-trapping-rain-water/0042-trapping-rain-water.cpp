class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n) , right(n);
        for (int i = 0 ; i < n; i++)
        {
            if (!i)
            {
                left[i] = height[i];
                continue;
            }
            left[i] = max(left[i-1] , height[i]);
        }
        for (int i = n-1; i >= 0 ; i--)
        {
            if (i == n-1)
            {
                right[i] = height[i];
                continue;
            }
            right[i] = max(height[i] , right[i+1]);
        }
        int ans = 0;
        for (int i = 1 ; i < n-1; i++)
        {
            int mini = min(left[i-1] , right[i+1]);
            ans += max(0 , mini - height[i]);
        }
        return ans;
    }
};