class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int> , vector<string>>mp;
        vector<int>count(26 , 0);
        for (int i = 0 ; i < strs.size(); i++)
        {
            for (int j = 0 ; j < strs[i].size(); j++)
            {
                char c = strs[i][j];
                count[c-'a']++;
            }
            mp[count].push_back(strs[i]);
            for (int j = 0 ; j < 26; j++)count[j] = 0;
        }
        for (auto x : mp)
        {
            vector<string>temp;
            for (auto z : x.second)
                temp.push_back(z);
            ans.push_back(temp);
        }
        
        return ans;
    }
};