class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numOfzeros = 0;
        int n = nums.size();
        int multiply = 1;
        for (int i = 0 ; i < n;  i++)
        {
            if (nums[i] == 0)
            {
                numOfzeros++;
                continue;
            }
            multiply *= nums[i];
        }
        if (numOfzeros > 1)
        {
            return vector<int>(n , 0);
        }
        vector<int>ans(n);
        for (int i = 0 ; i < n; i ++)
        {
            if (nums[i] != 0)
            {
                if (numOfzeros == 1)
                {
                    ans[i] = 0;
                }
                else ans[i] = multiply/nums[i];
            }
            else 
            {
                ans[i] = multiply;
            }
        }
        return ans;
    }
};