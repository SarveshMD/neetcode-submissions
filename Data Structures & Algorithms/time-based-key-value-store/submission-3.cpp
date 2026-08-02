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
        // for (auto& item: curr) {
        //     cout << item.first << " | " << item.second << endl;
        // }
        // cout << "timestamp: " << timestamp << endl;
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
        // cout << "k: " << k << endl;

        // for (auto& item: store) {
        //     cout << "name: " << item.first << endl;
        //     for (auto& item2: item.second) {
        //         cout << "    " << "timestamp: " << item2.first << " | " << item2.second << endl;
        //     }
        //     cout << endl;
        // }
        return (k == -1)?"":curr[k].second;
    }
};
