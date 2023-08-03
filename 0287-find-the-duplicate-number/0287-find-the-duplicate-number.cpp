class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int n = nums.size();
        for (int i = 0 ; i < n; i++)
        {
            if (mp[nums[i]])
                return nums[i];
            mp[nums[i]] = true;
        }
        return 1;
    }
};