class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size()-1;
        int area = 0;
        while (i < j)
        {
            int newArea = min(height[i] , height[j]) * (j - i);
            area = max(newArea , area);
            if (height[i] > height[j])
                j--;
            else i++;
        }
        return area;
    }
};