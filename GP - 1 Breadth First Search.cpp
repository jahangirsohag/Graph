#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int start)
{
	int V = adj.size();

	vector<int> res;

	queue<int> q;

	vector<bool> visited(V, false);

	visited[start] = true;

	q.push(start);

	while(!q.empty())
	{
		int current = q.front(); //Point the first element
		q.pop();				 //Remove first element, Now queue is empty at very first iteration

		res.push_back(current);  //Push_back into the result the pointed element

		for(int x : adj[current])//Iteration over the current nodes's all adjacency list
		{
			if(!visited[x])		 //Check if is not visited
			{
				visited[x] = true;//Mark as visited
				q.push(x);		  //Takes all the adjacent list's elements into the queue
			}
		}
	}
	return res;
}


signed main() {
	int n, e;
	cin >> n >> e;

	vector<vector<int>> adj(n + 1);

	for(int i = 1; i <= e; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> ans = bfs(adj, 1);

	for(int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}