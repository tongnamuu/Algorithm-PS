#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000
struct Edge {
	int to, cost;
};
vector<Edge>adj[501];
int d[501];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 2; i <= n; ++i) d[i] = INF;
	for (int i = 0, u, v, c; i < m; ++i) {
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
	}
	bool cycle = false;
	for (int i = 1; i <= n; ++i) {
		for (int now = 1; now <= n; ++now) {
			for (auto p : adj[now]) {
				int next = p.to;
				int cost = p.cost;
				if (d[now] != INF && d[next] > d[now] + cost) {
					d[next] = d[now] + cost;
					if (i == n) cycle = true;
				}
			}
		}
	}
	if (cycle) cout << -1;
	else {
		for (int i = 2; i <= n; ++i) {
			if (d[i] == INF) d[i] = -1;
			cout << d[i] << '\n';
		}
	}
}