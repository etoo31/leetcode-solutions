class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0 , e = nums.size()-1;
        int ans = nums[0];
        while (s <= e)
        {
            //cout << s << " " << e << endl;
            int mid = (s+e)/2;
            if (nums[mid] < ans)
            {
                e = mid -1;
                ans = nums[mid];
            }
            else s = mid + 1;
            //cout <<"after "<<  s << " " << e << endl;
        }
        return ans;
        
    }
};