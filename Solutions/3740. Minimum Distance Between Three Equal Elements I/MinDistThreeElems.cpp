class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int bestDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k] && nums[k] == nums[i]) {
                        int res = abs(i - j) + abs(j - k) + abs(k - i);
                        bestDist = min(bestDist, res);
                    }
                }
            }
        }

        if (bestDist == INT_MAX)
	        return -1;
        else return bestDist;
    }
};
