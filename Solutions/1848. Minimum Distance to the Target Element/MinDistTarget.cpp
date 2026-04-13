class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        if (n <= 1) return 0;

        // abs(i - start)

        int smallestDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                int res = abs(i - start);
                smallestDist = min(smallestDist, res);
            }
        }

        if (smallestDist == INT_MAX) return 0;
        else return smallestDist;
    }
};
