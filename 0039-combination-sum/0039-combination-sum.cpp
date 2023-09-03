class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0 , 0 , candidates, target);
        return ans;
    }
    void solve(int i, int sum,vector<int>& candidates, int& target)
    {
        if (sum >= target)
        {
            if (sum == target)
                ans.push_back(v);
            return;
        }
        if (i == candidates.size())
            return;
        
        //take
        v.push_back(candidates[i]);
        solve(i, sum + candidates[i] , candidates , target);
        //leave
        v.pop_back();
        solve(i+1, sum , candidates , target);
        
        
    }
};