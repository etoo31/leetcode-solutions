/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let mp = {};
    for (let n of nums)
    {
        if (!mp[n])mp[n] = 0;
        mp[n]++;
        if (mp[n] >1)return true;
    }
    return false;
};