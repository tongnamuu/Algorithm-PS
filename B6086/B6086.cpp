#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 1000000000;
struct Edge {
	int to, capacity;
	Edge* rev;
};
Edge edgePool[50000];
int edgeCnt = 0;
Edge* newEdge(int to, int cost) {
	edgePool[edgeCnt].to = to;
	edgePool[edgeCnt].capacity = cost;
	return &edgePool[edgeCnt++];
}
vector<Edge*>graph[100];
int Source;
int Sink;
int visit[52];

void add_edge(int u, int v, int capacity) {
	Edge* e= newEdge(v, capacity);
	Edge* rev = newEdge(u, 0);
	e->rev = rev;
	rev->rev = e;
	graph[u].push_back(e);
	graph[v].push_back(rev);
}
int dfs(int now, int dest, int c) {
	visit[now] = 1;
	if (now == dest) return c;
	for (int i = 0; i < graph[now].size(); ++i) {
		int next = graph[now][i]->to;
		int nc = graph[now][i]->capacity;
		if (visit[next] || nc <= 0) continue;
		int f = dfs(next, dest, min(c, nc));
		if (f > 0) {
			graph[now][i]->capacity -= f;
			graph[now][i]->rev->capacity += f;
			return f;
		}
	}
	return 0;
}

int flow() {
	int ans = 0;
	while (true) {
		fill(visit, visit + 52, 0);
		int f = dfs(Source, Sink, INF);
		if (f == 0) break;
		ans += f;
	}
	return ans;
}
int node(char ch) {
	if (ch >= 'a'&&ch <= 'z') return ch - 'a' + 26;
	else return ch - 'A';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Source = node('A');
	Sink = node('Z');
	int n; cin >> n;
	char u, v;
	int cost;
	for (int i = 0; i < n; ++i) {
		cin >> u >> v >> cost;
		add_edge(node(u), node(v), cost);
		add_edge(node(v), node(u), cost);
	}
	cout << flow() << '\n';
}