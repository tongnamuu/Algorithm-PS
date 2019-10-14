#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1000000000;

int cost[202][202];
int f[202][202];
int c[202][202];
int S = 0;
int E = 201;
vector<int>adj[202];

int from[202];
int dist[202];
bool inQ[202];
bool spfa(int& total_flow, int& total_cost) {
	fill(from, from + 202, -1);
	fill(dist, dist + 202, INF);
	queue<int>q;
	dist[S] = 0;
	inQ[S] = true;
	q.push(S);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		inQ[now] = false;
		for (int next : adj[now]) {
			if (c[now][next] - f[now][next] > 0 && dist[next] > dist[now] + cost[now][next]) {
				dist[next] = dist[now] + cost[now][next];
				from[next] = now;
				if (!inQ[next]) {
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}
	if (dist[E] == INF) return false;
	int flow = INF;
	for (int i = E; i != S; i = from[i]) {
		flow = min(flow, c[from[i]][i] - f[from[i]][i]);
	}
	for (int i = E; i != S; i = from[i]) {
		f[from[i]][i] += flow;
		f[i][from[i]] -= flow;
	}
	total_flow += flow;
	total_cost += flow * dist[E];
	return true;
}

int flow() {
	int f = 0;
	int total_cost = 0;
	while (spfa(f, total_cost)) {}
	return total_cost;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i + 100][E];
		adj[i + 100].push_back(E);
		adj[E].push_back(i + 100);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> c[S][i];
		adj[i].push_back(S);
		adj[S].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> cost[i][j + 100];
			cost[j + 100][i] = -cost[i][j + 100];
			c[i][j + 100] = INF;
			adj[i].push_back(j + 100);
			adj[j + 100].push_back(i);
		}
	}
	cout << flow() << '\n';
}