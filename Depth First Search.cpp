#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const long long INF = 4e18;

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void dfs(int source)
{
	cout << source << " ";
	visited[source] = true;

	for(int x : adj[source])
	{
		if(!visited[x])
		{
			dfs(x);
		}
	}
}

signed main()
{
	int n, e;
	cin >> n >> e;

	adj.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);

	for(int i = 0; i < e; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	
	return 0;
}