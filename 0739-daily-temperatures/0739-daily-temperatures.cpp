class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> ans(n);
        priority_queue<pair<int,int>>p;
        for (int i = 0 ; i < n; i++)
        {
            if (i)
            {
                solve(p ,temperatures[i] , ans  , i);
            }
            p.push({temperatures[i]*-1 , i});
        }
        

        return ans;
    }
    void solve(priority_queue<pair<int,int>>&p , int cur , vector<int>&ans , int i)
    {
        
        while (!p.empty()) {
        auto x = p.top();
        //cout << x.first << " " << x.second << endl;
        if (cur <= (x.first*-1))
            break;
        ans[x.second] = i-x.second;    
        p.pop();
        }
    }
};