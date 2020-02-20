#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000000
vector<pair<int,int>>adj[2001];
struct Edge {
	int from, cost;
	bool operator<(const Edge& a) const {
		return this->cost > a.cost;
	}
};
int hubo[101];
int n;
void getdist(int start, int* d) {
	priority_queue<Edge>q;
	q.push({ start,0 });
	d[start] = 0;
	while (!q.empty()) {
		int now = q.top().from;
		int cost = q.top().cost;
		q.pop();
		if (d[now] < cost) continue;
		for (int i = 0; i < adj[now].size(); ++i) {
			int next = adj[now][i].first;
			int c = adj[now][i].second + cost;
			if (d[next] > c) {
				d[next] = c;
				q.push({ next,c });
			}
		}
	}
}
int start[2001];
int first[2001];
void init() {
	for (int i = 1; i <= n; ++i) {
		first[i] = start[i] = INF;
		adj[i].clear();
	}
}
void solve() {
	int m, t; cin >> n >> m >> t;//교차로, 도로, 목적지 후보 개수
	init();
	int s, g, h; cin >> s >> g >> h;//예술가의 출발지, 현재는 g와 h사이의 도로에 있다.
	for (int i = 0; i < m; ++i) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	for (int i = 0; i < t; ++i) cin >> hubo[i];
	getdist(s, start);
	int next = start[g] > start[h] ? g : h;
	getdist(next, first);
	vector<int>ans;
	for (int i = 0; i < t; ++i) {
		if (start[next] + first[hubo[i]] > start[hubo[i]]) continue;
		ans.push_back(hubo[i]);
	}
	sort(ans.begin(), ans.end());
	for (int x : ans) cout << x << ' ';
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		solve();
	}
}