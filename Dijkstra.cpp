#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <cstdint>
#include <functional>

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,int>>> adj(n + 1);

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}


	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

	vector<int> dist(n + 1, 1e9);
	dist[1] = 0;

	vector<bool> vis(n + 1, false);

	pq.push({0, 1});

	while(!pq.empty())
	{
		auto [currDist, currNode] = pq.top();

		pq.pop();

		if(currDist > dist[currNode]) continue;

		for(auto [neighbor, edgeWeight] : adj[currNode])
		{
			int newDist = currDist + edgeWeight;

			if(dist[neighbor] > newDist)
			{
				dist[neighbor] = newDist;
				pq.push({newDist, neighbor});
			}
		}


	}

	for(int i = 1; i <= n; ++i)
	{
		cout << dist[i] << " ";
	}

	return 0;
}
