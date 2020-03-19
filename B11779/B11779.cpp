#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
struct Edge {
	int to, cost;
	bool operator<(const Edge& a) const {
		return this->cost > a.cost;
	}
};
vector<Edge>adj[1001];
int dist[1001];
int from[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0, u, v, c; i < m; ++i) {
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
	}
	int S, E; cin >> S >> E;
	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
		from[i] = -1;
	}
	priority_queue<Edge>q;
	q.push({ S,0 });
	dist[S] = 0;
	while (!q.empty()) {
		auto v = q.top(); q.pop();
		int now = v.to;
		if (dist[now] < v.cost) continue;
		for (auto p : adj[now]) {
			int next = p.to;
			int cost = v.cost + p.cost;
			if (dist[next] > cost) {
				dist[next] = cost;
				from[next] = now;
				q.push({ next,cost });
			}
		}
	}
	cout << dist[E] << '\n';
	vector<int>ans;
	for (int i = E; i != -1; i = from[i]) {
		ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
}