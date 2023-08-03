class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow , fast;
        slow = fast = 0;
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        int slow2 = 0;
        while (true)
        {
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow == slow2)
                break;
        }
        return slow;
    }
};