class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        deque<int>dq;
        vector<int>ans;
        for (int r = 0 ; r < n; r++)
        {
            while (!dq.empty() && nums[r] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(r);
            if (dq.front() < l)
                dq.pop_front();
            if (r-l+1 == k)
            {
                ans.push_back(nums[dq.front()]);
                l++;
            }
        }
        /*for(auto x : ans)
            cout << x << " ";*/
        return ans;
    }
};