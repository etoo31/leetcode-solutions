class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hash_table;
    vector<int> result;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int complement = target - nums[i];
        if(hash_table.find(complement) != hash_table.end()){
            result.push_back(hash_table[complement]);
            result.push_back(i);
            return result;
        }
        hash_table[nums[i]] = i;
    }
    return result;
                    
    }
};