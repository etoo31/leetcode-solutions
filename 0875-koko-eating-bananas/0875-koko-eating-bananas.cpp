class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1 , e = 1e9;
        int minik = 1e9;
        while (s <= e)
        {
            int k = (s+e)/2;
            long long calcH = 0;
            for (int i = 0 ; i < n; i++)
            {
                calcH += ceil(piles[i]*1.0/k);
            }
            if (calcH <= h)
            {
                cout << k << " " << calcH << " " << h << endl;
                
                e = k - 1;
                minik = min(k , minik);
            }
            else s = k + 1;
        }
        return minik;
    }
};