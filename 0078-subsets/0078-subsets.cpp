class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        solve(0 , nums);
        return ans;
        
    }
    void solve(int i,vector<int>&nums ){
        if (i == nums.size())
        {
            ans.push_back(v);
            return;
        }
        //leave
        solve(i+1, nums);
        //take
        v.push_back(nums[i]);
        solve(i+1 , nums);
        v.pop_back();
    }
};