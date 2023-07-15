class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int>mp;
        int n = nums.size();
        vector<int>ret;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int , int>>v;
        for (auto x : mp)
        {
         v.push_back({x.second , x.first});
        }
        sort(v.begin() , v.end());
        for (int i = v.size()-1; i >= 0; i--)
        {
            if (k)ret.push_back(v[i].second);
            else break;
            k--;
            
        }
        return ret;
    }
};