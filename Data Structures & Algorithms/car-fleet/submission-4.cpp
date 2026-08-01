class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;
        for (int i=0; i<n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        unordered_set<float> unique_set;
        vector<float> finishTimes(n);
        int fleets = 0;
        for (int i=0; i<n; i++) {
            finishTimes[i] = ((target - cars[i].first)*1.0) / cars[i].second;
            if (i > 0) finishTimes[i] = max(finishTimes[i], finishTimes[i-1]);
            if (!unique_set.contains(finishTimes[i])) {
                unique_set.insert(finishTimes[i]);
                fleets++;
            }
        }

        return fleets;
    }
};
