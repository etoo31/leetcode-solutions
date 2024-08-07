class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer , Integer>mp = new HashMap<>();
        for (int i = 0 ; i < nums.length; i++)
        {
            
            if (mp.containsKey(nums[i]))
            {
                return new int[]{mp.get(nums[i]) , i};
            }
            int needed = target - nums[i];
            mp.put(needed , i);
        }
        return new int[]{};
    }
}