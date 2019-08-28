#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
vector<pair<int,int>>a[40001];
int depth[40001];
int parent[40001];
int dist[40001];
int p[40001][17];
int lca(int u, int v) {
	if (depth[v] > depth[u]) {
		int temp = v;
		v = u;
		u = temp;
	}
	int log = 1;
	for (; (1 << log) <= depth[u]; ++log) {}
	log -= 1;
	for (int i = log; i >= 0; --i) {
		if (depth[u] - depth[v] >= (1 << i)) {
			u = p[u][i];
		}
	}
	if (u == v) return u;
	else {
		for (int i = log; i >= 0; --i) {
			if (p[u][i] != 0 && p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return parent[u];
	}
}
int main() {
	memset(dist, -1, sizeof(dist));
	int n; cin >> n;
	for (int i = 0, u, v, w; i < n - 1; ++i) {
		cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}
	queue<int>q;
	q.push(1);
	dist[1] = 0;
	depth[1] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto next : a[now]) {
			int nextv = next.first;
			int cost = next.second;
			if (depth[nextv] == 0) {
				depth[nextv] = depth[now] + 1;
				dist[nextv] = dist[now] + cost;
				parent[nextv] = now;
				q.push(nextv);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (p[i][j - 1] == 0) continue;
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	int m; cin >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		int x = lca(u, v);
		cout << dist[u] + dist[v] - 2 * dist[x] << '\n';
	}
}