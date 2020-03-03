#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define S 1
#define E 2
#define INF 1000000000
struct Edge {
	int to, cap;
	Edge* rev;
};
int EdgeCnt;
Edge EdgePool[60001];
Edge* newEdge(int v, int c) {
	EdgePool[EdgeCnt].to = v;
	EdgePool[EdgeCnt].cap = c;
	return &EdgePool[EdgeCnt++];
}
vector<Edge*>adj[801];
void add_edge(int u, int v, int c) {
	Edge* o = newEdge(v, c);
	Edge* r = newEdge(u, 0);
	o->rev = r;
	r->rev = o;
	adj[u].push_back(o);
	adj[v].push_back(r);
}
int level[801];
bool bfs() {
	fill(level, level + 801, -1);
	level[S] = 0;
	queue<int>q;
	q.push(S);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto p : adj[now]) {
			int next = p->to;
			if (level[next] == -1 && p->cap) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[E] != -1;
}
int index[801];
int dfs(int now, int c) {
	if (now == E) return c;
	for (int& i = index[now]; i < adj[now].size(); ++i) {
		int next = adj[now][i]->to;
		int nc = adj[now][i]->cap;
		if (level[next] == level[now] + 1 && nc) {
			int df = dfs(next, min(nc, c));
			if (df > 0) {
				adj[now][i]->cap -= df;
				adj[now][i]->rev->cap += df;
				return df;
			}
		}
	}
	return 0;
}
int flow() {
	int ans = 0;
	while (bfs()) {
		fill(index, index + 801, 0);
		while (1) {
			int f = dfs(S, INF);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		add_edge(u + n, v, INF);
		add_edge(v + n, u, INF);
	}
	for (int i = 3; i <= n; ++i) {
		add_edge(i, n + i, 1);
	}
	add_edge(1, 1 + n, INF);
	add_edge(2, 2 + n, INF);
	cout << flow();
}