class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n , 0);
        vector<int>right(n , 0);
        
        int r = 0;
        for (int i = 0 ; i < n; i++)
        {
            int trapped = r - height[i];
            if (trapped < 0)
                r = height[i];
            left[i] = max(0 , trapped);
        }
        int l = 0;
        for (int i = n-1 ; i >= 0; i--)
        {
            int trapped = l - height[i];
            if (trapped < 0)
                l = height[i];
            right[i] = max(0 , trapped);
        }
        int answer = 0;
        for (int i = 0 ; i < n; i++)
        {
            answer += min(right[i] , left[i]);
        }
        return answer;
    }
};