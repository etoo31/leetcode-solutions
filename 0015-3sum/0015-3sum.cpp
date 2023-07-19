class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ret;
        for (int x = 0 ; x < n; x++)
        {
            //cout << "x" << endl;
            if (x && nums[x] == nums[x-1])continue;
            int target = nums[x]*-1;
            
            int i = x+1, j = n-1;
            while (i < j)
            {
                //cout << "i : " << i << "  j : " << j << endl; 
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(vector<int>({nums[x] , nums[i] , nums[j]}));
                    while (i < j && nums[i] == nums[i+1])
                    {
                        i++;
                        cout << "i" << endl;
                    }
                    i++;
                }
                else if (nums[i] + nums[j] > target)
                {
                    j--;
                }
                else i++;
            }
            
        }
        return ret;
        
    }
};