#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

vector <vector <int>> g(N);
bool vis[N];

void dfs(int vertex) {

	/** Take action on vertex after entering
	*   the vertex
	**/
	vis[vertex] = true;
	cout << vertex << " ";
	for(int child : g[vertex])
	{

		/** Take action on child before
		 *  entering the child node
		 **/
		if(vis[child] == true) continue;
		dfs(child);

		/** Take action on child
		 *  after exiting child node
		 **/

	}

	/** Take action on vertex before
	 *  exiting the vertex
	 **/

}

signed main() {
	int n, m;
	cin >> n >> m;


	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
   	return 0;
}