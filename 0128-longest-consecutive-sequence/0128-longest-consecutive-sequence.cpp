class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        set<int>st;
        for (int i = 0 ; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (auto num : st)
        {
            if (st.find(num-1) == st.end())
            {
                int currentNum = num;
                int counter = 1;
                while (st.find(currentNum + 1) != st.end())
                {
                    currentNum++;
                    counter++;
                }
                ans = max(ans , counter);
            }
        }
        return ans;
    }
};