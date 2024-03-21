class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        
        int ans = 1;
        
        unordered_map<int , bool>mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = true;
        }
        for (int i = 0 ; i < nums.size(); i++)
        {
            if (mp[nums[i]-1] == false)
            {
                int count = 1;
                int n = nums[i]+1;
                while (mp[n])
                {
                    count++;
                    n++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
        
    }
};