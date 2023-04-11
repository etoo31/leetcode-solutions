class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int product = 1;
        vector<int>ans;
        for (int i = 0 ; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeros++;
            }
            else 
            {
                product *= nums[i];
            }
        }
        for (int i = 0 ; i < n; i++)
        {
            if (zeros == 0)
            {
                ans.push_back(product/nums[i]);
            }
            else if (zeros == 1)
            {
                if (nums[i] == 0)
                {
                    ans.push_back(product);
                }
                else ans.push_back(0);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};