class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    vector<bool>visted;
    vector<vector<int>> permute(vector<int>& nums) {
        visted = vector<bool>(nums.size() , false);
        solve(nums);
        return ans;
    }
    void solve(vector<int>& nums)
    {
        if (v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0 ; i < nums.size(); i++)
        {
            if (!visted[i])
            {
                v.push_back(nums[i]);//take
                visted[i] = true;
                solve(nums);
                visted[i] = false;
                v.pop_back();  //leave
            }
        }
    }
};