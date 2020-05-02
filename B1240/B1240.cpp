#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>>adj[1001];
int p[1001][21];
int depth[1001];
int d[1001];
int n;
int lca(int u, int v) {
	if (depth[u] < depth[v]) u ^= v ^= u ^= v;
	int log = 1;
	for (; (1 << log) <= n;++log);
	log -= 1;

	for (int i = log; i >= 0; --i) {
		if (depth[u] - depth[v] >= (1 << i)) {
			u = p[u][i];
		}
	}
	if (u == v) return u;
	for (int i = log; i >= 0; --i) {
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}
void dfs(int now, int parent) {
	depth[now] = depth[parent] + 1;
	p[now][0] = parent;
	for (auto p : adj[now]) {
		if (p.first == parent) continue;
		d[p.first] = d[now] + p.second;
		dfs(p.first, now);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int m; cin >> n >> m;
	for (int i = 1,u,v,c; i < n; ++i) {
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	dfs(1,1);
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		cout << d[u] + d[v] -  2*d[lca(u, v)] << '\n';
	}
}