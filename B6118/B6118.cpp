#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>a[20001];
int d[20001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	d[1] = 1;
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : a[now]) {
			if (d[next] == 0) {
				q.push(next);
				d[next] = d[now] + 1;
			}
		}
	}
	int ans = -1;
	int cnt = 0;
	int max_val = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i] > max_val) {
			max_val = d[i];
			ans = i;
			cnt = 1;
		}
		else if (d[i] == max_val) {
			cnt++;
		}
	}
	cout << ans << ' ' << max_val - 1 << ' ' << cnt << '\n';
}