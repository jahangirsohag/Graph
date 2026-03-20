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

struct Edge
{
	int u, v;
	long long w;
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<Edge> adj;

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj.push_back({a, b, c});
	}

	vector<int> parent(n + 1, -1);

	// Shortest path
	// vector<long long> dist(n + 1, 1e18);

	// Cycle detection (If is it disconnected component)
	vector<long long> dist(n + 1, 0);
	dist[1] = 0;

	int x = -1;

	for(int i = 1; i <= n; ++i)
	{
		x = -1;
		for(auto e : adj)
		{
			int u = e.u, v = e.v;
			long long w = e.w;

			if(dist[u] != 1e18 && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				x = v;
			}
		}
	}

	if(x == -1)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	for(int i = 1; i <= n; ++i)
	{
		x = parent[x];
	}
	vector<int> ans;
	int cur = x;
	do
	{
		ans.push_back(cur);
		cur = parent[cur];
	}while(cur != x);
	ans.push_back(x);
	reverse(ans.begin(), ans.end());
	for(auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
