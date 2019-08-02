#include <iostream>
using namespace std;
int a[101][101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 1000;
		}
	}
	for (int i = 0, from, to; i < m; ++i) {
		cin >> from >> to;
		a[from][to] = 1;
		a[to][from] = 1;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	int cnt = 2147483647;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][0] += a[i][j];
		}
		if (cnt > a[i][0]) {
			cnt = a[i][0];
			ans = i;
		}
	}
	cout << ans << '\n';
}