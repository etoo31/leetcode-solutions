class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0 , r = n-1;
        int maxLeft = 0 , maxRight = 0;
        int ans = 0;
        while ( l < r)
        {
            maxLeft = max(maxLeft , height[l]);
            maxRight = max(maxRight , height[r]);
            if (maxLeft > maxRight)
            {
                r--;
                ans += max(0 , maxRight - height[r]);
            }
            else 
            {
                l++;
                ans += max(0 , maxLeft - height[l]);
            }
        }
        return ans;
    }
};