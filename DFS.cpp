#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const int N = 1e5 + 9;

int tree[N];

vector <int> g[N];
bool vis[N];

void dfs(int u)
{
    vis[u] = true;
    for(auto v : g[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

signed main() {

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> components;

    for(int u = 1; u <= n; ++u)
    {
        if(!vis[u])
        {
            components.push_back(u);
            dfs(u);
        }
    }

    cout << components.size() - 1 << endl;
    for(int i = 0; i < components.size() - 1; ++i)
    {
        cout << components[i] << " " << components[i + 1] << endl;
    }
    return 0;
}