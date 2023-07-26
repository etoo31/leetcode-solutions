class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total/2;
        int s= 0 , e = nums1.size()-1;
        while (true)
        {
            cout << s << " " << e << endl;
            int i = (s + e) /2;
            int j = half - i - 2;
            int A1 = getValue(i , nums1);
            int A2 = getValue(i+1 , nums1);
            int B1 = getValue(j , nums2);
            int B2 = getValue(j+1 , nums2);
            cout << A1 << " " << B2 << " " << B1 <<" " <<  A2 << endl;
            cout << "i = " << i << "   j = " << j << endl;
            if (A1 <= B2 && B1 <= A2)
            {
                cout << "In" << endl;
                cout << A1 << " " << B2 << endl;
                if (total % 2)
                {
                    return (double)min(B2, A2);
                }
                else return (max(B1, A1)+min(B2, A2))/2.0;
            }
            else if (A1 > B2)
            {
                if (e == i-1)
                    e = i - 2;
                else e = i - 1;
            }
            else s = i + 1;
        }
        if (total%2)
        {
            return (double)nums2[half];
        }
        else return (nums2[half]+nums2[half-1])/2.0;
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