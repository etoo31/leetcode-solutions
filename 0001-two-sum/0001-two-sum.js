/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let mp = {};
    for (let index in nums)
        {
            if (mp[nums[index]])
                return [mp[nums[index]] , index];
            mp[target - nums[index]] = index;
            
        }
    return [];
};