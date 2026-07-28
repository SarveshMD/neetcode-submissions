class Solution {
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> max_pref(n, 0);
        vector<int> max_suf(n, 0);
        for (int i=1; i<n; i++) {
            max_pref[i] = max(max_pref[i-1], height[i-1]);
        }
        for (int i=n-2; i>=0; i--) {
            max_suf[i] = max(max_suf[i+1], height[i+1]);
        }

        int total_vol = 0;
        for (int i=0; i<n; i++) {
            int bound = min(max_pref[i], max_suf[i]);
            total_vol += max(0, bound - height[i]);
        }
        return total_vol;
    }
};
