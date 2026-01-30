class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
    // vector<vector<int>> edges = {{0,1,3},
	// 	{3,1,1},
	// 	{2,3,4},
	// 	{0,2,2}
	// };

	// int n = 4;
	int src = 0;
	vector<vector<pair<int, int>>> adj(n);

	// Make adj list
	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		int c = edges[i][2];

		adj[u].push_back({v, c}); // from start -> end, to cost
		adj[v].push_back({u, c * 2}); // reversal, end -> start, to cost * 2
	}

	int V = adj.size();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<int> dist(V, INT_MAX);

	// Distance from source to itself
	dist[src] = 0;
	pq.emplace(0, src);

	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();

		int d = top.first;
		int u = top.second;

		// If this distance not the latest shortest one, skip it
		if (d > dist[u])
			continue;

		// Explore all neighbors of the current vertex
		//auto [v, w] : adj[u]
		// auto &p : adj[u]
		// For all pairs
		for (auto &p : adj[u]) {
			int v = p.first;
			int w = p.second;
			// If we found a shorter path to v through u, update it
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}

    if (dist[n-1] == INT_MAX) 
        return -1;
    else
        return dist[n - 1];

    }
};
