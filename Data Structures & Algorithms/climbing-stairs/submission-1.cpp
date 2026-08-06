class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a = 1;
        int b = 1;
        for (int i=0; i<n-1; i++) {
            int tmp = b;
            b += a;
            a = tmp;
        }
        return b;
    }
};
