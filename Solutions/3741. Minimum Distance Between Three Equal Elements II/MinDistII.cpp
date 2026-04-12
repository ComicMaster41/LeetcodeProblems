class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return -1;

        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }

        int minCost = INT_MAX;
        for (auto idx : map) {
            for (int h = 0; h < (int)idx.second.size() - 2; h++) {
                int i = idx.second[h];
                int k = idx.second[h+2];

                int res = 2 * (k - i);

                minCost = min(minCost, res);
            }
        }

        if (minCost == INT_MAX) return -1;
        else return minCost;
    }
};
