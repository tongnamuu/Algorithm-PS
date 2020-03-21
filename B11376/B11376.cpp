#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1002
int n, m;
vector<int>adj[N];
void add_edge(int from, int to) {
	adj[from].push_back(to);
}
bool check[N];
int pred[N];
int dfs(int now) {
	if (now == -1) return 1;
	for (int next : adj[now]) {
		if (!check[next]) {
			check[next] = true;
			if (dfs(pred[next])) {
				pred[next] = now;
				return 1;
			}
		}
	}
	return 0;
}
int match() {
	int ans = 0;
	fill(pred, pred + N, -1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			fill(check, check + N, false);
			ans += dfs(i);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int T, w; cin >> T;
		while (T--) {
			cin >> w;
			add_edge(i, w);
		}
	}
	cout << match();
}