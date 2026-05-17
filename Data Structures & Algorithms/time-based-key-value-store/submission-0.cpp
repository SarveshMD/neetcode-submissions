class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> time_map;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        vector<pair<int,string>> items = time_map[key];
        int l = 0, r = items.size()-1;
        int m;
        while (l <= r) {
            m = (l+r)/2;
            if (items[m].first == timestamp) return items[m].second;
            else if (items[m].first < timestamp) {
                res = items[m].second;
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return res;
    }
};
