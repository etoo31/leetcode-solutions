class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total /2;
        int s = 0 , e = nums1.size()-1;
        while (true)
        {
            int i = (s+e)/2;
            int j = half - i -2;
            
            double a1 = getValue(i , nums1);
            double a2 = getValue(i+1 , nums1);
            
            double b1 = getValue(j , nums2);
            double b2 = getValue(j+1 , nums2);
            
            // cout << i << " " << j << endl;
            // cout << a1 << " " << b2 << endl;
            // cout << b1 << " " << a2 << endl;
            if (a1 <= b2 && b1 <= a2)
            {
                if (total%2)
                    return min(a2 , b2);
                else return (max(a1 , b1) + min(a2,b2))/2.0;
            }
            if (a1 > b2)
            {
               
                  if (e == i-1)
                    e = i - 2;
                else e = i - 1;
            }
            else s = i+1;
        }
        
        return 1.0;
    }
    int getValue(int index , vector<int>&v)
    {
        if (index < 0)
        {
            return -10000000;
        }
        else if (index >= v.size())
            return 10000000;
        return v[index];
    }
};