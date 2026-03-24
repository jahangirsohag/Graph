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
 
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, m;
	cin >> n >> m;
 
	vector<vector<int>> adj(n);
	vector<int> indegree(n, 0);
 
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
 
		adj[a].push_back(b);
		indegree[b]++;
	}
 
	queue<int> q;
	vector<int> topoOrder;
 
	for(int i = 0; i < n; ++i)
	{
		if(indegree[i] == 0) q.push(i);
	}
 
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		topoOrder.push_back(node);
 
		for(int neighbor : adj[node])
		{
			indegree[neighbor]--;
			if(indegree[neighbor] == 0) q.push(neighbor);
		}
	}
 
	if((int)topoOrder.size() != n)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	for(int i : topoOrder)
	{
		cout << i + 1 << " ";
	}
	cout << endl;
 
	return 0;