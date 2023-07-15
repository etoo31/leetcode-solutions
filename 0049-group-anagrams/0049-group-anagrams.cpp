class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n = strs.size();
        unordered_map<string , vector<string>>mp;
        for (int i = 0 ; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin() , s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>>v;
        for (auto x : mp)
        {
            v.push_back(x.second);
        }
        return v;
    }
};