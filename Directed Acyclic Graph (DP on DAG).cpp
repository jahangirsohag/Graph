#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <cstdint>
#include <functional>

using namespace std;

struct Edge
{
	int u, v;
	long long w;
};

void dfs(int node, const vector<vector<int>> &adj, vector<int> &vis, vector<int> &topo, int &index)
{
	vis[node] = true;
	for(int neighbor : adj[node])
	{
		if(!vis[neighbor])
		{
			dfs(neighbor, adj, vis, topo, index);
		}
	}
	topo[index] = node;
	index -= 1;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
	}

	vector<int> topo(n);
	vector<int> vis(n, 0);
	int index = n - 1;

	for(int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs(i, adj, vis, topo, index);
		}
	}

	vector<int> dist(n, 0);
	dist[0] = 1;
	vector<int> parent(n);

	for(int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}

	bool startFound = false;

	for(int node : topo)
	{
		if(!startFound)
		{
			if(node == 0) startFound = true;
			else continue;
		}

		for(int neighbor : adj[node])
		{
			if(dist[node] + 1 > dist[neighbor])
			{
				dist[neighbor] = dist[node] + 1;
				parent[neighbor] = node;
			}
		}
	}

	if(dist[n - 1] == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<int> path;
	int current = n - 1;
	while(parent[current] != current)
	{
		path.push_back(current);
		current = parent[current];
	}
	path.push_back(current);

	reverse(path.begin(), path.end());

	// cout << dist[n - 1] << endl;
	cout << path.size() << endl;
	for(int node : path)
	{
		cout << node + 1 << " ";
	}
	cout << endl;



	return 0;
}
