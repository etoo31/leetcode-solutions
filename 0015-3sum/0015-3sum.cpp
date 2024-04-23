class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        
        for (int index = 0 ;  index < nums.size(); index++)
        {
            int target = nums[index] * -1;
            if (index && nums[index] == nums[index-1])
                continue;
            int i = index +1 , j = nums.size()-1;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int>v({nums[index] , nums[i] , nums[j]});
                    ans.push_back(v);
                }
                if (nums[i] + nums[j] < target){
                    i++;
                    while (i < j && nums[i] == nums[i-1])
                    {
                        i++;
                    }
                }
                else {
                    j--;
                    while(j > i && nums[j] == nums[j+1])
                    {
                        j--;
                    }
                }
            }
        }
        return ans;
        
    }
};