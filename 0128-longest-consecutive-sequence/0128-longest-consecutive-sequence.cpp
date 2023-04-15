class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)return 0;
        int ans = 1;
        int counter = 0;
        int lastNum;
        map<int , bool>mp;
        for (int i = 0 ; i < n; i++)
        {
            mp[nums[i]] =true;
        }
        
        for (auto x : mp)
        {
            //cout << x.first << endl;
            if (counter == 0)
            {
                lastNum = x.first;
                counter = 1;
                continue;
            }
            if (x.first == lastNum+1)
            {
                counter++;
                lastNum = x.first;
            }
            else
            {
                ans = max(ans , counter);
                counter =1;
                lastNum = x.first;
            }
        }
        ans = max(ans , counter);
        return ans;
    }
};