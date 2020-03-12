#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define S 0
#define E 10000
struct Edge {
	int to, cap;
	Edge* rev;
};
Edge edge[1000000];
int EdgeCnt;
Edge* newEdge(int to, int c) {
	edge[EdgeCnt].to = to;
	edge[EdgeCnt].cap = c;
	return &edge[EdgeCnt++];
}
vector<Edge*>adj[E + 1];
void add_edge(int from, int to, int cap) {
	Edge* e = newEdge(to, cap);
	Edge* r = newEdge(from, 0);
	e->rev = r;
	r->rev = e;
	adj[from].push_back(e);
	adj[to].push_back(r);
}
int level[E + 1];
bool bfs() {
	fill(level + 1, level + E + 1, -1);
	queue<int>q;
	q.push(S);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto p : adj[now]) {
			int next = p->to;
			if (level[next] == -1 && p->cap) {
				q.push(next);
				level[next] = level[now] + 1;
			}
		}
	}
	return level[E] != -1;
}
int index[E + 1];
int dfs(int now, int c) {
	if (now == E) return c;
	for (int& i = index[now]; i < adj[now].size(); ++i) {
		int next = adj[now][i]->to;
		int nc = adj[now][i]->cap;
		if (level[next] == level[now] + 1 && nc) {
			int df = dfs(next, nc);
			if (df) {
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
		fill(index, index + E + 1, 0);
		while (1) {
			int f = dfs(S, 10000000);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}
int a[101][101];
int r[101][101];
int c[101][101];
void init(int n, int m) {
	int numbering = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 2) continue;
			if (r[i][j - 1]) r[i][j] = r[i][j - 1];
			else r[i][j] = ++numbering;
		}
	}
	int K = numbering;
	for (int i = 1; i <= K; ++i) {
		add_edge(S, i, 1);
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (a[i][j] == 2) continue;
			if (c[i - 1][j]) c[i][j] = c[i - 1][j];
			else c[i][j] = ++numbering;
		}
	}
	for (int i = K + 1; i <= numbering; ++i) {
		add_edge(i, E, 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	init(n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 0) {
				add_edge(r[i][j], c[i][j], 1);
			}
		}
	}
	cout << flow();
}