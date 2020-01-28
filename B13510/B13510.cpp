#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100001
int seg[4 * SIZE];
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) {
		seg[node] = val;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
int query(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return 0;
	if (i <= start && end <= j) return seg[node];
	return max(query(node * 2, start, (start + end) / 2, i, j), query(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
struct Edge {
	int from, to, weight;
	Edge(int u, int v, int w) { from = u, to = v, weight = w; }
};
vector<Edge>edge;
vector<pair<int, int>>adj[SIZE];
int w[SIZE];
int p[SIZE];
int d[SIZE];
void dfs(int now) {
	w[now] = 1;
	for (auto& v : adj[now]) {
		int next = v.first;
		if (!w[next]) {
			p[next] = now;
			d[next] = d[now] + 1;
			dfs(next);
			w[now] += w[next];
		}
	}
}
int numbering;
int num[SIZE];
int hld[SIZE];//n이 속한 정점이 속한 구간에서 가장 깊이가 작은 정점의 번호
int idx[SIZE];//numbering이 n인 노드의 index
void dfs2(int now) {
	int cc = -1;
	num[now] = ++numbering;
	idx[num[now]] = now;
	for (auto& v : adj[now]) {
		int next = v.first;
		if (p[next] == now && (cc == -1 || w[cc] < w[next])) cc = next;
	}
	if (cc != -1) {
		hld[cc] = hld[now];
		dfs2(cc);
	}
	for (auto& v : adj[now]) {
		int next = v.first;
		if (p[next] == now && next != cc) {
			hld[next] = next;
			dfs2(next);
		}
	}
}
void init(int root) {
	p[root] = root;
	hld[root] = root;
	dfs(root);
	dfs2(root);
}
int lca(int u, int v) {
	while (hld[u] != hld[v]) {
		if (d[hld[u]] > d[hld[v]]) u = p[hld[u]];
		else v = p[hld[v]];
	}
	return d[u] < d[v] ? u : v;
}
void hld_update(int n, int u, int v, int val) {
	if (d[u] > d[v]) swap(u, v);
	update(1, 1, n, num[v], val);
}
int hld_subquery(int n, int u, int v) {
	int ret = 0;
	while (hld[u] != hld[v]) {
		ret = max(ret, query(1, 1, n, num[hld[u]], num[u]));
		u = p[hld[u]];
	}
	ret = max(ret, query(1, 1, n, num[v] + 1, num[u]));
	return ret;
}
int hld_query(int n, int u, int v) {
	int x = lca(u, v);
	return max(hld_subquery(n, u, x), hld_subquery(n, v, x));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edge.push_back({ u,v,w });
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	init(1);
	for (int i = 0; i < n - 1; ++i) {
		int from = edge[i].from;
		int to = edge[i].to;
		int weight = edge[i].weight;
		hld_update(n, from, to, weight);
	}
	int m; cin >> m;
	while (m--) {
		int cmd, x, y; cin >> cmd >> x >> y;
		if (cmd == 1) {
			--x;
			edge[x].weight = y;
			hld_update(n, edge[x].from, edge[x].to, y);
		}
		else {
			cout << hld_query(n, x, y) << '\n';
		}
	}
}
