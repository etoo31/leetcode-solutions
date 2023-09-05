class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        solve(0 , 0, candidates , target);
      
        return ans;
    }
    void solve(int i,int sum,vector<int>& candidates, int& target)
    {
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }
        if (sum > target)return;
        
        
        int prev = -1;
        for (int pos = i ; pos < candidates.size(); pos++){
            if (prev == candidates[pos])
                continue;
            //take
            v.push_back(candidates[pos]);
            solve(pos+1, sum + candidates[pos] , candidates , target);
            //leave
            v.pop_back();
            prev = candidates[pos];
        }
    }
};