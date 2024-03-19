class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int>pre , inv;
         for (int i = 0 ; i < nums.size(); i++)
         {
             if (i)
             pre.push_back(nums[i] * pre[i-1]);
             else pre.push_back(nums[i]);
             inv.push_back(nums[i]);
         }
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (i == nums.size()-1)continue;
            
                inv[i] *= inv[i+1];
        }
        vector<int>ans;
        for (int i = 0 ; i < nums.size(); i++)
        {
        
            if (i == nums.size()-1)
            {
                ans.push_back(pre[i-1]);
            }
            else if (i == 0)
            {
                ans.push_back(inv[i+1]);
            }
            else 
            {
                ans.push_back(pre[i-1] * inv[i+1]);
            }
          

        }
                return ans;
            
    }
};