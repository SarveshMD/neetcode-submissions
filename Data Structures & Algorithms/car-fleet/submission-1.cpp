class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;// pairs of {position, speed}
        for (int i=0; i<position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        stack<double> stk;
        int fleets = 0;
        double prev = 0;
        for (int i=0; i<pairs.size(); i++) {
            double curr = (target - pairs[i].first)/((float)(pairs[i].second));
            if (prev < curr) {
                fleets++;
                prev = curr;
            }
        }
        return fleets;
    }
};
