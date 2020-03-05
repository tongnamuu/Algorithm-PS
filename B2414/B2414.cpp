#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define S 0
#define E 5001
#define INF 1000000000
char a[51][51];
int row[51][51];
int col[51][51];
int K, M;
struct Edge {
	int to, cap;
	Edge* rev;
};
Edge EdgePool[20000];
int EdgeCnt;
Edge* newEdge(int v, int c) {
	EdgePool[EdgeCnt].to = v;
	EdgePool[EdgeCnt].cap = c;
	return &EdgePool[EdgeCnt++];
}
vector<Edge*>adj[5002];
void add_edge(int u, int v, int c) {
	Edge* o = newEdge(v, c);
	Edge* r = newEdge(u, 0);
	o->rev = r;
	r->rev = o;
	adj[u].push_back(o);
	adj[v].push_back(r);
}
int level[5002];
bool bfs() {
	fill(level, level + 5002, -1);
	queue<int>q;
	q.push(S);
	level[S] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto p : adj[now]) {
			int next = p->to;
			int c = p->cap;
			if (level[next] == -1 && c) {
				q.push(next);
				level[next] = level[now] + 1;
			}
		}
	}
	return level[E] != -1;
}
int index[5002];
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
		fill(index, index + 5002, 0);
		while (1) {
			int f = dfs(S, INF);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}
void init(int n, int m) {
	int numbering = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.') continue;
			if (j > 0 && a[i][j - 1] == '*') {
				row[i][j] = numbering;
			}
			else {
				row[i][j] = ++numbering;
			}
		}
	}
	M = numbering;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (a[i][j] == '.') continue;
			if (i > 0 && a[i - 1][j] == '*') {
				col[i][j] = numbering;
			}
			else {
				col[i][j] = ++numbering;
			}
		}
	}
	K = numbering;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	init(n, m);
	for (int i = 1; i <= M; ++i) add_edge(S, i, 1);
	for (int i = M + 1; i <= K; ++i) add_edge(i, E, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (row[i][j] && col[i][j]) {
				add_edge(row[i][j], col[i][j], 1);
			}
		}
	}
	cout << flow();
}