class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i == nums1.size())
            {
                v.push_back(nums2[j]);
                j++;
            }
            else if (j == nums2.size())
            {
                v.push_back(nums1[i]);
                i++;
            }
            else if (nums2[j] < nums1[i])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else {
                v.push_back(nums1[i]);
                i++;

            }
        }
        int n = v.size();
        if (n%2)
        {
            return (double)v[n/2];
        }
        else 
            return (v[n/2]+ v[(n/2)-1])/2.0;
        //return 2.000000;
    }
};