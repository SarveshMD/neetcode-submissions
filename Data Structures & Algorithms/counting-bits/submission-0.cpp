class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i=0; i<=n; i++) {
            int j = i;
            int count = 0;
            while (j > 0) {
                count += j%2;
                j >>= 1;
            }
            res[i] = count;
        }
        return res;
    }
};
