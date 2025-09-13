#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const long long INF = 4e18;

using namespace std;

int parent[100];

void init()
{
	for(int i = 1; i <= 8; ++i)
	{
		parent[i] = i;
	}
}

bool flag = false;

int find(int u)
{
	cout << "Called with " << u << endl;
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void Union(int u, int v)
{
	int p = find(u);
	int q = find(v);

	if(p != q)
	{
		parent[q] = p;
	}
}

bool isSameSet(int u, int v)
{
	int p = find(u);
	int q = find(v);

	return (p == q);
}

signed main()
{
	init();

	Union(1, 2);
	Union(2, 3);
	Union(3, 4);
	Union(4, 5);

	// cout << find(1) << " " << find(5) << endl;

	// if(isSameSet(1, 6)) cout << "true" << endl;
	// else cout << "false" << endl;

	flag = true;

	cout << find(5) << endl;
	cout << "--------------" << endl;
	cout << find(5) << endl;
	cout << "-------------" << endl;

	cout << find(4) << endl;

	cout << "--------------------" << endl;


	return 0;
}