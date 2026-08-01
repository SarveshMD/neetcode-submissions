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

        vector<float> finishTimes(n);
        for (int i=0; i<n; i++) {
            finishTimes[i] = ((target - cars[i].first)*1.0) / cars[i].second;
        }

        for (int i=1; i<n; i++) {
            finishTimes[i] = max(finishTimes[i], finishTimes[i-1]);
        }

        unordered_set<float> unique_set;
        int fleets = 0;
        for (float f: finishTimes) {
            if (unique_set.contains(f)) continue;
            unique_set.insert(f);
            fleets++;
        }
        return fleets;
    }
};
