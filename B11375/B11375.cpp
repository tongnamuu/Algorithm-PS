#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>adj[1001];
int pred[1001];
int check[1001];
int n;
void add_edge(int from, int to) {
	adj[from].push_back(to);
}
int dfs(int now) {
	if (now == -1) return 1;
	for (int next : adj[now]) {
		if (check[next]) continue;
		check[next] = true;
		if (dfs(pred[next])) {
			pred[next] = now;
			return 1;
		}
	}
	return 0;
}
int flow() {
	int ans = 0;
	fill(pred, pred + n + 1, -1);
	for(int i=1;i<=n;++i){
		fill(check, check + n + 1, false);
		if (dfs(i)) ++ans;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x;
		while (x--) {
			cin >> y;
			adj[i].push_back(y);
		}
	}
	n = max(n, m);
	cout << flow();
}