// NOTE: this implementation doesn't solve the problem because a TIME EXCEED is hit

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // QUESTION: do we set the variables to i for nums?
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;
            while (idx <= r && idx < n) {
                nums[idx] = (long long)(nums[idx]) * v % (1000000007);
                idx += k;
            }
            // comp at the top566r
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }

        return res;
    }
};

