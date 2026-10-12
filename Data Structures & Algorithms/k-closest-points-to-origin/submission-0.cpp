class Solution {
public:
    static double distanceToOrigin(vector<int> point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        decltype([](const auto& a, const auto& b) {
            return distanceToOrigin(a) > distanceToOrigin(b);
        })> pq;

        for (auto point: points) {
            pq.push(point);
        }

        vector<vector<int>> res;
        for (int i=0; i<k; i++) {
            res.push_back(pq.top());
            pq.pop();;
        }

        return res;
    }
};
