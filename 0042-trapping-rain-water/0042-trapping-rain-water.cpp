class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int maxLeft = 0 , maxRight = 0;
        int i = 0 , j = height.size()-1;
        while (i < j)
        {
            maxLeft = max(maxLeft , height[i]);
            maxRight = max(maxRight , height[j]);
            if (height[i] > height[j])
            {
                j--;
                if (j != i)
                {
                    int temp = maxRight - height[j];
                    if (temp > 0)
                        ans += temp; 
                }
            }
            else 
            {
                i++;
                if (i != j)
                {
                    int temp = maxLeft - height[i];
                    if (temp > 0)
                        ans += temp;
                }
            }
        }
        return ans;
        
    }
};