#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define N 801
#define INF 1000000000
struct Edge {
	int v, c;
	bool operator<(const Edge& a) const {
		return v > a.v;
	}
};
vector<Edge>adj[N];
int dist[3][801];
int s[3];
void dijkstra(int idx) {
	for (int i = 1; i < N; ++i) dist[idx][i] = INF;
	priority_queue<Edge>q;
	q.push({ s[idx],0 });
	dist[idx][s[idx]] = 0;
	while (!q.empty()) {
		int now = q.top().v;
		int c = q.top().c;
		q.pop();
		if (dist[idx][now] < c) continue;
		for (auto p : adj[now]) {
			int next = p.v;
			int nc = p.c + c;
			if (dist[idx][next] > nc) {
				dist[idx][next] = nc;
				q.push({ next,nc });
			}
		}
	}
}
int getans(int n) {
	if (dist[0][s[1]] == INF) return INF;
	if (dist[1][s[2]] == INF) return INF;
	if (dist[2][n] == INF) return INF;
	return dist[0][s[1]] + dist[1][s[2]] + dist[2][n];
}
int getans2(int n) {
	if (dist[0][s[2]] == INF) return INF;
	if (dist[2][s[1]] == INF) return INF;
	if (dist[1][n] == INF) return INF;
	return dist[0][s[2]] + dist[2][s[1]] + dist[1][n];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	s[0] = 1;
	cin >> s[1] >> s[2];
	for (int i = 0; i < 3; ++i) {
		dijkstra(i);
	}
	int ans = min(getans(n), getans2(n));
	if (ans == INF) cout << -1;
	else cout << ans;
}