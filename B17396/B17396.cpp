#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 100001
#define INF 100000000000LL
int a[N];
long long d[N];
struct Edge {
	int to;
	long long cap;
	bool operator<(const Edge& a) const {
		return this->cap > a.cap;
	}
};
vector<Edge>adj[N];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		d[i] = INF;
	}
	a[n - 1] = 0;
	for (int i = 0, u, v; i < m; ++i) {
		long long c;
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	priority_queue<Edge>q;
	d[0] = 0;
	q.push({ 0,0 });
	while (!q.empty()) {
		int now = q.top().to;
		long long c = q.top().cap;
		q.pop();
		if (d[now] < c) continue;
		for (auto p : adj[now]) {
			int next = p.to;
			if (a[next]) continue;
			long long cap = p.cap + c;
			if (d[next] > cap) {
				d[next] = cap;
				q.push({ next,cap });
			}
		}
	}
	if (d[n - 1] == INF) d[n - 1] = -1;
	cout << d[n - 1];
}