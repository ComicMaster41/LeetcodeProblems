class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // initalize parent array for Union-Find
        int n = source.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // Make each element as its own parent

        // Create the find the leader function
        function<int(int)> findLeader = [&](int x) {
            if (x == parent[x]) {
                return x;
            }

            return parent[x] = findLeader(parent[x]);
        };

        // Merge two people to a single leader
        for (auto& swap : allowedSwaps) {
            int leader1 = findLeader(swap[0]);
            int leader2 = findLeader(swap[1]);
            parent[leader1] = leader2; // union two components
        }

        // count freq of each value in source array for each connected component
        // Key: component leader, Value: map of (value -> freq)
        unordered_map<int, unordered_map<int, int>> compValCt;
        for (int i = 0; i < n; ++i) {
            int leader = findLeader(i);
            compValCt[leader][source[i]]++; // increase count of value
        }

        // calculate min hamm dist
        int dist = 0;
        for (int i = 0; i < n; ++i) {
            int leader = findLeader(i);

            // decrease count of target[i] in component
            // If count becomes negative, it means we don't have enough of this value in the component to match the target

            if (--compValCt[leader][target[i]] < 0) dist++;
        }

        return dist;
    }
};
