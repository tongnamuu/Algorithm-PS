#include <iostream>
#include <vector>
using namespace std;
vector<int>adj[100001];
int w[100001];
void dfs(int now) {
	w[now] = 1;
	for (int next : adj[now]) {
		if (!w[next]) {
			dfs(next);
			w[now] += w[next];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, root, q; cin >> n >> root >> q;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(root);
	for (int i = 0, u; i < q; ++i) {
		cin >> u; cout << w[u] << '\n';
	}
}