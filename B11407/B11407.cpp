#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define N 203
#define S 0
#define E 201
#define INF 1000000000
struct Edge {
	int to, cap, cost;
	Edge* rev;
};
Edge edge[50000];
int edgeCnt;
Edge* newEdge(int to, int cap, int cost) {
	edge[edgeCnt].to = to;
	edge[edgeCnt].cap = cap;
	edge[edgeCnt].cost = cost;
	return &edge[edgeCnt++];
}
vector<Edge*> adj[N];
void add_edge(int from, int to, int cap, int cost) {
	Edge* e = newEdge(to, cap, cost);
	Edge* r = newEdge(from, 0, -cost);
	e->rev = r;
	r->rev = e;
	adj[from].push_back(e);
	adj[to].push_back(r);
}
bool inQ[N];
int dist[N];
pair<int,int> from[N];
bool spfa(int& total_flow, int& total_cost) {
	fill(&from[0], &from[N],make_pair(-1,-1));
	fill(inQ, inQ + N, false);
	fill(dist, dist + N, INF);
	dist[S] = 0;
	queue<int>q;
	q.push(S);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		inQ[now] = false;
		for (int i = 0; i < adj[now].size(); ++i) {
			int next = adj[now][i]->to;
			int cap = adj[now][i]->cap;
			int cost = adj[now][i]->cost;
			if (cap && dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				from[next] = { now,i };
				if (!inQ[next]) {
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}
	if(dist[E]==INF) return false;
	int nc = INF;
	for (int x = E; from[x].first != -1; x = from[x].first) {
		int c = adj[from[x].first][from[x].second]->cap;
		nc = min(c, nc);
	}
	for (int x = E; from[x].first != -1; x = from[x].first) {
		Edge* e = adj[from[x].first][from[x].second];
		e->cap -= nc;
		e->rev->cap += nc;
	}
	total_flow += nc;
	total_cost += nc * dist[E];
	return true;
}
void flow() {
	int total_flow = 0;
	int total_cost = 0;
	while (spfa(total_flow, total_cost));
	cout << total_flow << ' ' << total_cost;
}
int max_book[101][101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		add_edge(S, i, x, 0);
	}
	for (int i = 1, x; i <= m; ++i) {
		cin >> x;
		add_edge(i + 100, E, x, 0);
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> max_book[j][i];
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1, x; i <= n; ++i) {
			cin >> x;
			add_edge(i, j + 100, max_book[j][i], x);
		}
	}
	flow();
}