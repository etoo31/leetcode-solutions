class Solution {
public:
    set<vector<int>>st;
    vector<int>v;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        solve(0 , nums);
        for (auto x : st)
            ans.push_back(x);
        return ans;
    }
    void solve(int i ,vector<int>& nums)
    {
        if (i == nums.size())
        {
            st.insert(v);
            return;
        }
        v.push_back(nums[i]);
        solve(i+1, nums); // take
        v.pop_back();
        solve(i+1 , nums); // leave
    }
};