class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        if (n == 1) return 1;
        for (int i=1; i<n; i++) {
            int tmp = b;
            b += a;
            a = tmp;
        }
        return b;
    }
};
