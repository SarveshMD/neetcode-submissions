class Solution {
public:
    pair<int, int> full_adder(int a, int b, int cin) {
        int sum = a ^ b ^ cin;
        int carry = a&b | a&cin | b&cin;
        return {sum, carry};
    }

    int getSum(int a, int b) {
        uint32_t ua = static_cast<unsigned>(a);
        uint32_t ub = static_cast<unsigned>(b);
        int res = 0;
        int cout = 0;
        for (int i=0; i<32; i++) {
            int bita = (ua>>i) % 2;
            int bitb = (ub>>i) % 2;
            pair<int, int> out = full_adder(bita, bitb, cout);
            int sum = out.first;
            cout = out.second;
            res = res | (sum << i);
        }
        return res;
    }
};
