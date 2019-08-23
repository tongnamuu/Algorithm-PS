#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>>adj[1001];
priority_queue<int> dist[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0, a, b, w; i < m; ++i) {
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
	}
	dist[1].push(0);
	priority_queue<pair<int, int>>q;
	q.push({ 0,1 });
	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		for (int i = 0; i < adj[now].size(); ++i) {
			int next = adj[now][i].first;
			if (dist[next].size() < k || dist[next].top() > cost + adj[now][i].second) {
				if (dist[next].size() == k) {
					dist[next].pop();
				}
				dist[next].push(cost + adj[now][i].second);
				q.push({ -(cost + adj[now][i].second),next });
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (dist[i].size() != k) {
			cout << -1 << '\n';
		}
		else cout << dist[i].top() << '\n';
	}
}