#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge {
	int to;
	int capacity;
	Edge* rev;
	Edge() {
		to = 0;
		capacity = 0;
	}
};
Edge edgePool[200000];
int edgeCnt;
Edge* newEdge(int to, int cost) {
	edgePool[edgeCnt].to = to;
	edgePool[edgeCnt].capacity = cost;
	return &edgePool[edgeCnt++];
}
const int INF = 1000000000;

int Source = 0;
int Sink = 1001;
vector<Edge*>adj[1002];
int level[1002];

void add_edge(int u, int v, int c) {
	Edge* o = newEdge(v, c);
	Edge* r = newEdge(u, 0);
	o->rev = r;
	r->rev = o;
	adj[u].push_back(o);
	adj[v].push_back(r);
}

bool bfs() {
	fill(level, level + 1002, -1);
	queue<int>q;
	level[Source] = 0;
	q.push(Source);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto next : adj[now]) {
			if (level[next->to] == -1 && next->capacity > 0) {
				level[next->to] = level[now] + 1;
				q.push(next->to);
			}
		}
	}
	return level[Sink] != -1;
}

int dfs(int now, int dest, int c) {
	if (now == dest) return c;
	for (auto next : adj[now]) {
		if (level[next->to] == level[now] + 1 && next->capacity > 0) {
			int df = dfs(next->to, dest, min(c, next->capacity));
			if (df > 0) {
				next->capacity -= df;
				next->rev->capacity += df;
				return df;
			}
		}
	}
	return 0;
}

int flow() {
	int ans = 0;
	while (bfs()) {
		while (1) {
			int f = dfs(Source, Sink, INF);
			if (f == 0) break;
			ans += f;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		add_edge(Source, i, 1);
		add_edge(i + 500, Sink, 1);
	}
	for (int i = 0, u, v; i < k; ++i) {
		cin >> u >> v;
		add_edge(u, v + 500, 1);
	}
	int ans = flow();
	cout << ans << '\n';
}