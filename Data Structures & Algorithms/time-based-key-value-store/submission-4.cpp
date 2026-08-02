class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> curr = store[key];
        auto iter = upper_bound(curr.begin(), curr.end(), timestamp, [](int value, const pair<int, string>& p) {
            return value < p.first;
        });
        
        int k = -1;
        if (iter == curr.begin()) {
            k = -1;
        }
        else {
            --iter;
            k = iter - curr.begin();
        }
        return (k != -1) ? curr[k].second : "";
    }
};
