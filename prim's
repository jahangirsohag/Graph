#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
#include <cstdint>

using namespace std;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n + 1);

	for(int i = 0; i < m; ++i)
	{
		int b, e, w;
		cin >> b >> e >> w;
		adj[b].push_back({e, w});
		adj[e].push_back({b, w});
	}

	vector<bool> visited(n + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	long long minCost = 0;

	pq.push({0, 1});

	while(!pq.empty())
	{
		auto [weight, node] = pq.top();
		pq.pop();

		if(visited[node]) continue;

		visited[node] = true;
		minCost += weight;

		for(auto [nextNode, nextWeight] : adj[node])
		{
			if(!visited[nextNode])
			{
				pq.push({nextWeight, nextNode});
			}
		}
	}
	cout << minCost << endl;

	return 0;
}
