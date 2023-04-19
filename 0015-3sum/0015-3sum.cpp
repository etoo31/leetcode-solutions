class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      int n = nums.size();
      //sort the input vector
      sort(nums.begin(), nums.end());

      for (int i = 0; i < n - 2; i++) {
        // check for duplicates
          if (i > 0 && nums[i] == nums[i-1]) continue;
          // calculating the target value
          int target = nums[i]*-1;

          int left = i + 1, right = n - 1;
          while (left < right) {
              int sum = nums[left] + nums[right];

              if (sum == target) {
                  res.push_back({nums[i], nums[left], nums[right]});

                // check for duplicates
               while (left < right && nums[left] == nums[left+1]) left++;
               left++;
        
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
        return res;
    }
};