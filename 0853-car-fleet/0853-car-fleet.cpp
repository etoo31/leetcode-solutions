class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n = speed.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back({position[i] , speed[i]});
        }
        sort(v.begin() , v.end());
        stack<pair<int,double>>st;
        for (int i = n-1; i >= 0; i--)
        {
            double reachTime = (double)(target - v[i].first)/(double)v[i].second;
            cout << v[i].first << " " << reachTime << endl;
            if (!st.empty() && reachTime <= st.top().second)
            {
                continue;
            }
            st.push({v[i].first , reachTime});
        }
        return st.size();
    }
};