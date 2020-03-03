#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define SOURCE 1
#define SINK 2
int n, m;
struct Edge {
	int to, capacity;
	Edge* rev;
};
Edge EdgePool[100001];
int EdgeCnt;
Edge* newEdge(int to, int cap) {
	EdgePool[EdgeCnt].to = to;
	EdgePool[EdgeCnt].capacity = cap;
	return &EdgePool[EdgeCnt++];
}
vector<Edge*>adj[401];
void add_edge(int u, int v, int c) {
	Edge* e = newEdge(v, c);
	Edge* r = newEdge(u, 0);
	e->rev = r;
	r->rev = e;
	adj[u].push_back(e);
	adj[v].push_back(r);
}
int level[401];
int index[401];
bool bfs() {
	fill(level, level + n + 1, -1);
	level[SOURCE] = 0;
	queue<int>q;
	q.push(SOURCE);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto p : adj[now]) {
			int next = p->to;
			if (level[next] == -1 && p->capacity) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[SINK] != -1;
}
int dfs(int now, int c) {
	if (now == SINK) return c;
	for (int& i = index[now]; i < adj[now].size(); ++i) {
		int next = adj[now][i]->to;
		int nc = adj[now][i]->capacity;
		if (level[next] == level[now] + 1 && nc) {
			int df = dfs(next, min(c, nc));
			if (df > 0) {
				adj[now][i]->capacity -= df;
				adj[now][i]->rev->capacity += df;
				return df;
			}

		}
	}
	return 0;
}
int flow() {
	int ans = 0;
	while (bfs()) {
		fill(index, index + n + 1, 0);
		while (1) {
			int f = dfs(SOURCE, 1000000000);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		add_edge(u, v, 1);
	}
	cout << flow();
}