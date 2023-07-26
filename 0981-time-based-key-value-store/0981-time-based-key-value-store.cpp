class TimeMap {
private:
    map<string , vector<pair<int,string>>>mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        int s = 0 , e = mp[key].size()-1;
        string ans;
        while (s <= e)
        {
            int mid = (s+e)/2;
            if (mp[key][mid].first <= timestamp)
            {
                ans = mp[key][mid].second;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */