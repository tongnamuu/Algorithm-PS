#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define S 0
#define E 201
#define N 203
struct Edge {
	int to, cap;
	Edge* rev;
};
Edge edge[50001];
int edgeCnt;
Edge* newEdge(int to, int cap) {
	edge[edgeCnt].to = to;
	edge[edgeCnt].cap = cap;
	return &edge[edgeCnt++];
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
int work[N];
int dfs(int now, int c) {
	if (now == E) return c;
	for (int& i = work[now]; i < adj[now].size(); ++i) {
		int next = adj[now][i]->to;
		int nc = adj[now][i]->cap;
		if (level[next] == level[now] + 1 && nc) {
			int df = dfs(next, min(nc, c));
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
		fill(work, work + N, 0);
		while (1) {
			int f = dfs(S, 1000000);
			if (!f) break;
			ans += f;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		add_edge(S, i, x);
	}
	for (int i = 1, x; i <= m; ++i) {
		cin >> x;
		add_edge(i + 100, E, x);
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1, x; i <= n; ++i) {
			cin >> x;
			add_edge(i, j + 100, x);
		}
	}
	cout << flow();
}