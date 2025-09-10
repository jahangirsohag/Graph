#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const long long INF = 4e18;

using namespace std;

signed main()
{
	int n, e;
	cin >> n >> e;

	vector<vector<pair<int, long long>>> adj(n + 1);

	for(int i = 0; i < e; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	vector<long long> dist(n + 1, INF);
	vector<int> parent(n + 1, -1);

	pq.push({0, 1});

	dist[1] = 0;

	while(!pq.empty())
	{
		int current = pq.top().second;
		long long current_dist = pq.top().first;

		pq.pop();

		if(current_dist > dist[current]) continue;	//If

		for(auto &edge: adj[current])
		{
			int next = edge.first;			//Next node
			long long weight = edge.second;		//Cost of path to get next node

			if(current_dist + weight < dist[next])	//if(current_dist + edge.second < dist[next])
			{
				dist[next] = current_dist + weight;
				parent[next] = current;
				pq.push({dist[next], next});
			}
		}
	}

	int destination = n;

	if(dist[destination] == 4e18)
	{
		cout << -1 << endl;
	}
	else
	{
		vector<int> path;
		for(int v = destination; v != -1; v = parent[v])
		{
			path.push_back(v);
		}
		reverse(path.begin(), path.end());

		for(int node : path)
		{
			cout << node << " ";
		}
		cout << endl;
	}

	return 0;
}