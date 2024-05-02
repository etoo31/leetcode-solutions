class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>carsInfo(n);
        for (int i = 0 ; i < n; i++)
        {
            carsInfo[i].first = position[i];
            carsInfo[i].second = speed[i];
        }
        sort(carsInfo.begin() , carsInfo.end());
        stack<double>st;
        for (int i = 0; i < n; i++)
        {
            double arrivalTime = (target - carsInfo[i].first)/(carsInfo[i].second*1.0);
            while (!st.empty() && st.top() <= arrivalTime)
            {
                st.pop();
            }
            st.push(arrivalTime);
        }
        return st.size();
    }
};