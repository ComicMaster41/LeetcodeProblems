class Solution {
public:
    int numTrees(int n) {
        // this almost sounds like how many different ways can you rearrange a given number 
        if (n <= 1) return 1;

        unsigned long int res = 0;
        for (int i = 0; i < n; ++i) {
            res += numTrees(i) * numTrees(n - i - 1);
        }

        return res;
    }
};
