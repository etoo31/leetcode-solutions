class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1 , e = 1e9+2;
        int ans = 1e9+2;
        while (s <= e)
        {
            int k = (long long)(s+e)/2;
            long long time = 0;
            for (int i = 0 ; i < piles.size(); i++)
            {
                //cout << "piles : " << piles[i] << "  k = " << k << endl;
                //cout << piles[i] << " / " << k  << "  =  " << ceil((double)piles[i]/k) << endl;
                time += ceil((double)piles[i]/k);
            }
            if (time <= h){
                ans = min(ans , k);
                e = k - 1;
            }
            else s = k +1 ;
            
        }
        return ans;
    }
};