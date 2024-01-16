class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        
        map<int , int>mp;
        for (int i = 0 ; i < nums.size(); i++)
        {
            int needed = target - nums[i];
            if (mp.find(needed) != mp.end())
            {
                ans = vector<int>({mp[needed] , i});
                break;
            }
            //cout << needed << endl;
            mp[nums[i]] = i;
        }
        return ans;
        
    }
};