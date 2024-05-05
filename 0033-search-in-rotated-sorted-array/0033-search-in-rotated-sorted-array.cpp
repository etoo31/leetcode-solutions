class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        bool greaterThanTheFirst;
        if (nums[0] <= target)
            greaterThanTheFirst = true;
        else greaterThanTheFirst = false;
        
        int s = 0 , e = nums.size()-1;
        while (s <= e)
        {
            int mid = (s+e)/2;
            if (nums[mid] == target)
                return mid;
            if (greaterThanTheFirst)
            {
                if (nums[mid] < nums[0]  || nums[mid] > target)
                    e = mid -1;
                else s = mid +1;
            }
            else 
            {
                if (nums[mid] >= nums[0] || nums[mid] < target)
                    s = mid +1;
                else e = mid -1;
            }
        }
        return -1;
    }
};