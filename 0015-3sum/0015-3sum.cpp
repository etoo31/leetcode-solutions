class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for (int i = 0 ; i < n; i++)
        {
            if (i && nums[i] == nums[i-1])
                continue;
            
            int target = nums[i]*-1;
            int j = i+1 , k = n-1;
            while (j < k)
            {
                if (nums[j] + nums[k] > target)
                {
                    k--;
                }
                else if (nums[j]+nums[k] < target)
                    j++;
                else
                {
                    ans.push_back(vector<int>{nums[i] , nums[j] , nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j-1])j++;
                }
                    
            }
        }
        return ans;
    }
};