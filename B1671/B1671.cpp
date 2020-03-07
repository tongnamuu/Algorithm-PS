#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
using namespace std;
#define S 0
#define E 101
struct Edge {
	int to, cap;
	Edge* rev;
};
Edge EdgePool[10000];
int EdgeCnt;
Edge* newEdge(int to, int c) {
	EdgePool[EdgeCnt].to = to;
	EdgePool[EdgeCnt].cap = c;
	return &EdgePool[EdgeCnt++];
}
vector<Edge*>adj[103];
void add_edge(int from, int to, int c) {
	Edge* e = newEdge(to, c);
	Edge* r = newEdge(from, 0);
	e->rev = r;
	r->rev = e;
	adj[from].push_back(e);
	adj[to].push_back(r);
}
int level[103];
bool bfs() {
	memset(level, -1, sizeof(level));
	queue<int>q;
	q.push(S);
	level[S] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto p : adj[now]) {
			int next = p->to;
			if ((level[next] == -1) && p->cap ) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[E] != -1;
}
int ind[103];
int dfs(int now, int c) {
	if (now == E) return c;
	for (int& i = ind[now]; i < adj[now].size(); ++i) {
		int next = adj[now][i]->to;
		int nc = adj[now][i]->cap;
		if ((level[next] == level[now] + 1) && nc ) {
			int df = dfs(next, min(c, nc));
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
		memset(ind, 0, sizeof(ind));
		while (1) {
			int f = dfs(S, 1000000000);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}
struct Shark {
	int sz, v, intel;
	bool operator<(const Shark& a) const {
		return this->sz <= a.sz&&this->v <= a.v&&this->intel <= a.intel;
	}
	bool operator==(const Shark& a) const {
		return this->sz == a.sz&&this->v == a.v&&this->intel == a.intel;
	}
};
Shark shark[51];
bool eatable(int u, int v) {
	if (u == v) return false;
	if (shark[u]==shark[v]) return u < v;
	return shark[v] < shark[u];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> shark[i].sz >> shark[i].v >> shark[i].intel;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (eatable(i, j)) {
				add_edge(i, j + 50, 1);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		add_edge(S, i, 2);
		add_edge(i + 50, E, 1);
	}
	cout << n - flow();
}
