#include <iostream>
#include <vector>
using namespace std;
vector<int>a[50001];
int parent[50001];
int depth[50001];
void go(int node, int d) {
	depth[node] = d + 1;
	for (int next : a[node]) {
		if (depth[next] == 0) {
			parent[next] = node;
			go(next, d + 1);
		}
	}
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) {
		int temp = x;
		x = y;
		y = temp;
	}
	while (depth[x] != depth[y]) x = parent[x];
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	return x;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	depth[1] = 1;
	for (int next : a[1]) {
		parent[next] = 1;
		go(next, 1);
	}
	int m; cin >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}