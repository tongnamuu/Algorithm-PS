#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 10002
#define S 0
#define E 10001
int map[102][102];
int row[102][102];
int col[102][102];
struct Edge {
	int to, cap;
	Edge* rev;
};
Edge EdgePool[1000000];
int EdgeCnt;
Edge* newEdge(int to, int c) {
	EdgePool[EdgeCnt].to = to;
	EdgePool[EdgeCnt].cap = c;
	return &EdgePool[EdgeCnt++];
}
vector<Edge*>adj[N];
void add_edge(int from, int to, int cap) {
	Edge* e = newEdge(to, cap);
	Edge* r = newEdge(from, 0);
	e->rev = r;
	r->rev = e;
	adj[from].push_back(e);
	adj[to].push_back(r);
}
int level[N];
bool bfs() {
	fill(level + 1, level + N, -1);
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
int index[N];
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
		fill(index, index + N, 0);
		while (1) {
			int f = dfs(S, 1000000);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		map[u][v] = 1;
	}
	int numbering = 0;
	for (int i = 1; i <= n; ++i) {
		for (int x = i, y = 1; x <= n && y <= n; x++, y++) {
			if (map[x][y]) continue;
			if (row[x - 1][y - 1] && !map[x][y] ) {
				row[x][y] = row[x - 1][y - 1];
			}
			else {
				row[x][y] = ++numbering;
			}
		}
		if (i == 1) continue;
		for (int x = 1, y = i; x <= n && y <= n; x++, y++) {
			if (map[x][y]) continue;
			if (row[x - 1][y - 1] && !map[x][y]) {
				row[x][y] = row[x - 1][y - 1];
			}
			else {
				row[x][y] = ++numbering;
			}
		}
	}
	int k = numbering + 1;
	for (int i = 1; i <= numbering; ++i) {
		add_edge(S, i, 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int x = 1, y = i; x <= n && y > 0; ++x, --y) {
			if (map[x][y]) continue;
			if (col[x - 1][y + 1] && !map[x][y]) {
				col[x][y] = col[x - 1][y + 1];
			}
			else {
				col[x][y] = ++numbering;
			}
		}
		if (i == 1) continue;
		for (int x = i, y = n; x <= n && y > 0; ++x, y--) {
			if (map[x][y]) continue;
			if (col[x - 1][y + 1] && !map[x][y]) {
				col[x][y] = col[x - 1][y + 1];
			}
			else {
				col[x][y] = ++numbering;
			}
		}
	}
	for (int i = k; i <= numbering; ++i) {
		add_edge(i, E, 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (row[i][j] && col[i][j]) {
				add_edge(row[i][j], col[i][j], 1);
			}
		}
	}
	cout << flow();
}