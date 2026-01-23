#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 2) { // special case
                ans.push_back(-1);
            } else {
                int p = nums[i];

                // mask is our "sliding window" bit probe
                int mask = 1;

                // Move left while the current bit in p is 1
                while ((p & mask) != 0) {
                    mask <<= 1;
                }

                // mask is now at the first 0 bit after trailing 1s,
                // so move back one step
                int sub = mask >> 1;

                int res = p - sub;
                ans.push_back(res);
            }
        }
