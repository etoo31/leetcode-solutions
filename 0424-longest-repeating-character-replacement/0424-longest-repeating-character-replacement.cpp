class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0;
        int ans = 0;
        int arr[26] = {};
        for (int i = 0 ; i < n; i++)
        {
            arr[s[i]-'A']++;
            int windowLength = i-j+1;
            while (windowLength - getMaxi(arr) > k)
            {
                arr[s[j]-'A']--;
                j++;
                windowLength = i-j+1;
            }
            ans = max(ans , windowLength);
        }
        return ans;
    }
    int getMaxi(int arr[])
    {
        int maxi = arr[0];
        for (int i = 1 ; i < 26; i++)
            maxi = max(maxi , arr[i]);
        return maxi;
    }
};