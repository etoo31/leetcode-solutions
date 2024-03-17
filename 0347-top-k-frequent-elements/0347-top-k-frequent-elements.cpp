
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        for (int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int , int>>v;
        vector<int>ans;
        for (auto pair : mp)
        {
            v.push_back(pair);
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.second > y.second;
        });
        for (int i = 0 ; i < k ; i++)
            ans.push_back(v[i].first);
        return ans;
    }
    
   
};