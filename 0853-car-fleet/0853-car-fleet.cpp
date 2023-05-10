class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        stack<pair<int , int>>st;
        
        int n = speed.size();
        for (int i = 0 ;i  < n; i++)
        {
            v.push_back({position[i] , speed[i]});
        }
        sort(v.begin() , v.end());
        for (int i = n-1 ; i >= 0; i--)
        {
            //cout << v[i].first << " " << v[i].second << endl;
            if (st.size() == 0 || st.top().second >= v[i].second)
            {
                st.push({v[i].first , v[i].second});
            }
            else if (st.top().second < v[i].second)
            {
                auto lastCar = st.top();
                double sec1 = abs((double)(target - lastCar.first)/(double)(lastCar.second));
                double sec2 = abs((double)(target - v[i].first)/((double)v[i].second));
                //cout << sec1 << " " << sec2 << endl;
                if (sec1 < sec2)
                {
                    st.push({v[i].first , v[i].second});
                }
            }
        }
        return st.size();
        
    }
};