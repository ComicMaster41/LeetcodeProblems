
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // min
        int maxVal = 0;

        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] + nums[nums.size() - 1 - i] > maxVal) {
                maxVal = nums[i] + nums[nums.size() - 1 - i];
            }
        }
        
        return maxVal;
    }
};

