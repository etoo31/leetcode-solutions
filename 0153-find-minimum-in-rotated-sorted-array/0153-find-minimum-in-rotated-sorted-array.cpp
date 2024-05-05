class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0 , e = nums.size()-1;
        int ans = nums[0];
        while (s <= e)
        {
            int mid = (s+e)/2;
            if (nums[mid] < ans){
                ans = nums[mid];
                e = mid -1;   
            }
            else {
                s = mid +1;
            }
        }
        return ans;
    }
};