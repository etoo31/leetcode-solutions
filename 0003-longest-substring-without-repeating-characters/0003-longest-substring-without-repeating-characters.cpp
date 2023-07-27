class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , bool>arr;
        int n = s.size();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while(arr[s[i]])
            {
                arr[s[j]] = 0;
                j++;
            }
            arr[s[i]] = true;
            ans = max(ans , i-j+1);
        }
        return ans;
    }
};