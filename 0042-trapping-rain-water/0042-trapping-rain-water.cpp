class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL = height[0] , maxR = height[n-1];
        int l = 0 , r = n-1;
        int ans = 0;
        char which;
        
        while (l < r)
        {
            if (which == 'L')
            {
                ans += max(0 , maxL - height[l]);
                maxL = max(maxL , height[l]);
            }
            else if (which =='R')
            {
                ans += max(0 , maxR - height[r]);
                maxR = max(maxR , height[r]);
            }
            if (maxL > maxR)
             {
                r--;
                which ='R';
             }
            else {
                l++;
                which = 'L';
            }
        }
        return ans;
        
    }
};