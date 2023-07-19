class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)return 0; 
        map<int , bool>mp;
        for (int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]] = 1;
        }
        int ret = 1;
        int last = -1e9-3;
        int count = 0;
        //cout << last << endl;
        for (auto n : mp)
        {
            //cout << n.first << endl;
            if (n.first == last+1)
            {
                count++;
                last = n.first;
                continue;
            }
            ret = max(count+1 , ret);
            count = 0;
            last = n.first;
        }
        ret = max(count+1 , ret);
        return ret;
    }
};