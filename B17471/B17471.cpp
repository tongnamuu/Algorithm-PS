#include <iostream>
#include <vector>
using namespace std;
int a[11];
vector<int>adj[11];
int ans = -1;
int color[11];
bool visit[11];
void dfs(int now, int c) {
	visit[now] = true;
	for (int next : adj[now]) {
		if (color[next] == c && !visit[next]) {
			dfs(next, c);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		int m; cin >> m;
		while (m--) {
			int x; cin >> x;
			adj[i].push_back(x);
		}
	}

	for (int i = 1; i < (1 << (n + 1)); ++i) {
		vector<int>left;
		vector<int>right;
		for (int j = 1; j <= n; ++j) {
			visit[j] = false;
			if (i&(1 << j)) {
				left.push_back(j);
				color[j] = 1;
			}
			else {
				right.push_back(j);
				color[j] = 2;
			}
		}
		if (left.size() == 0 || right.size() == 0) continue;
		dfs(left[0], 1);
		dfs(right[0], 2);
		bool ok = true;
		for (int j = 1; j <= n; ++j) {
			if (!visit[j]) {
				ok = false; break;
			}
		}
		if (ok) {
			int sum1 = 0, sum2 = 0;
			for (int x : left) {
				sum1 += a[x];
			}
			for (int x : right) {
				sum2 += a[x];
			}
			sum1 = sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
			if (ans == -1 || ans > sum1) ans = sum1;
		}
	}
	cout << ans << '\n';
}