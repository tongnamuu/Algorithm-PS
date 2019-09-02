#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>>a[100001];
int depth[100001];
int dist[100001];
int p[100001][17];
int mindist[100001][17];
int maxdist[100001][17];
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
pair<int, int> lca(int u, int v) {
	if (depth[v] > depth[u]) {
		int temp = v;
		v = u;
		u = temp;
	}
	int mind = 10000000;
	int maxd = 0;

	int log = 1;
	for (; (1 << log) <= depth[u]; ++log) {}
	log--;

	for (int i = log; i >= 0; --i) {
		if (depth[u] - depth[v] >= (1 << i)) {
			mind = min(mind, mindist[u][i]);
			maxd = max(maxd, maxdist[u][i]);
			u = p[u][i];
		}
	}
	if (u == v) return { mind,maxd };
	else {
		for (int i = log; i >= 0; --i) {
			if (p[u][i] != 0 && p[u][i] != p[v][i]) {
				mind = min(mind, mindist[u][i]);
				maxd = max(maxd, maxdist[u][i]);
				mind = min(mind, mindist[v][i]);
				maxd = max(maxd, maxdist[v][i]);
				u = p[u][i];
				v = p[v][i];
			}
		}
		mind = min(mind, mindist[u][0]);
		maxd = max(maxd, maxdist[u][0]);
		mind = min(mind, mindist[v][0]);
		maxd = max(maxd, maxdist[v][0]);
		return { mind,maxd };
	}
}
void go(int now) {
	for (auto k : a[now]) {
		int next = k.first;
		int cost = k.second;
		if (depth[next] == 0) {
			depth[next] = depth[now] + 1;
			dist[next] = dist[now] + cost;
			mindist[next][0] = cost;
			maxdist[next][0] = cost;
			p[next][0] = now;
			go(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}
	depth[1] = 1;
	dist[1] = 0;
	go(1);
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (p[i][j - 1] == 0) continue;
			p[i][j] = p[p[i][j - 1]][j - 1];
			mindist[i][j] = mindist[i][j - 1];
			maxdist[i][j] = maxdist[i][j - 1];
			if (p[i][j] == 0) continue;
			mindist[i][j] = min(mindist[i][j - 1], mindist[p[i][j - 1]][j - 1]);
			maxdist[i][j] = max(maxdist[i][j - 1], maxdist[p[i][j - 1]][j - 1]);
		}
	}
	int m; cin >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		pair<int, int>x = lca(u, v);
		cout << x.first << ' ' << x.second << '\n';
	}
}