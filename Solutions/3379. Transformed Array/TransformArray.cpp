class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if (n == 0) {
            return result;
        }

        if (n == 1) {
            // what happens if there's only one thing in the list
            result.push_back(nums[0]);
            return result;
        }

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int shift = (val + i) % n;
            if (val > 0) {
                result.push_back(nums[shift]);
            }

            else if (val < 0) {
                if (shift < 0) shift += n;
                result.push_back(nums[shift]);
            }

            else if (val == 0) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};
