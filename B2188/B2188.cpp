#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 203
vector<int>adj[N];
int pre[N];
bool check[N];
void init() {
	for (int i = 0; i < N; ++i) {
		pre[i] = -1;
	}
}
void add_edge(int from, int to) {
	adj[from].push_back(to);
}
int dfs(int now) {
	if (now == -1) return 1;
	for (int next : adj[now]) {
		if (!check[next]) {
			check[next] = true;
			if (dfs(pre[next])) {
				pre[next] = now;
				return 1;
			}
		}
	}
	return 0;
}
int flow(int n) {
	init();
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		fill(check, check + N, false);
		ans += dfs(i);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1, x, num; i <= n; ++i) {
		cin >> x;
		while (x--) {
			cin >> num;
			add_edge(i, num);
		}
	}
	cout << flow(n);
}