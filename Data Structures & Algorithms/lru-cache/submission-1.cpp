class LRUCache {
public:
    unordered_map<int, int> cache;
    vector<pair<int, int>> order_list;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        int value = (it != cache.end()) ? it->second : -1;
        if (value != -1) {
            int i;
            for (i=0; i<order_list.size(); i++) {
                if (order_list[i].first == key) break;
            }
            auto tmp = order_list[i];
            order_list.erase(order_list.begin() + i);
            order_list.push_back(tmp);
        }
        return value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        int val = (it != cache.end()) ? it->second : -1;
        if (val != -1) {
            int i;
            for (i=0; i<order_list.size(); i++) {
                if (order_list[i].first == key) break;
            }
            order_list.erase(order_list.begin() + i);
        }
        cache[key] = value;
        order_list.push_back({key, value});
        if (order_list.size() > capacity) {
            cache.erase(order_list[0].first);
            order_list.erase(order_list.begin());
        }
    }
};
