class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> res;
      int n = nums.size();

      sort(nums.begin(), nums.end());

      for (int i = 0; i < n - 2; i++) {
        // check for duplicates
          if (i > 0 && nums[i] == nums[i-1]) continue;

          int left = i + 1, right = n - 1;

          while (left < right) {
              int sum = nums[i] + nums[left] + nums[right];

              if (sum == 0) {
                  res.push_back({nums[i], nums[left], nums[right]});

                // check for duplicates
               while (left < right && nums[left] == nums[left+1]) left++;
               left++;
        
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
        return res;
    }
};