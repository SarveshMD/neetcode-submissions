class Solution {
public:
    static int distSq(vector<int> point) {
        return point[0]*point[0] + point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        decltype([](const auto& a, const auto& b) {
            return distSq(a) > distSq(b);
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
