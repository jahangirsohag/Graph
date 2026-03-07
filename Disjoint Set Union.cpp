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

const int N = 2e5;

int parent[N];
int rnk[N];

int find(int x)
{
	if(parent[x] == x)
	{
		return x;
	}
	return parent[x] = find(parent[x]);
}

void Union(int u, int v)
{
	int p = find(u);
	int q = find(v);

	if(p == q) return;

	if(rnk[p] < rnk[q])
	{
		parent[p] = q;
	}
	else if(rnk[p] > rnk[q])
	{
		parent[q] = p;
	}
	else
	{
		parent[q] = p;
		rnk[p] += 1;
	}
}

int32_t main()
{
	int n, q;
	cin >> n >> q;

	for(int i = 0; i < n; ++i)
	{
		parent[i] = i;
		rnk[i] = 0;
	}


	return 0;
}


