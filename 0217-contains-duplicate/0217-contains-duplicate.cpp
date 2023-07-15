class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int>mp;
        int n = nums.size();
        for (int i = 0 ; i < n; i++)
        {
            int x = ++mp[nums[i]];
            if (x > 1)return 1;
        }
        return 0;
    }
};