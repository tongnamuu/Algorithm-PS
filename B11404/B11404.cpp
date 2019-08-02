#include <iostream>
using namespace std;
int a[101][101];
int min(int x, int y) { return x > y ? y : x; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 1000000000;
		}
	}
	for (int i = 0, from, to, cost; i < m; ++i) {
		cin >> from >> to >> cost;
		if (a[from][to] > cost) {
			a[from][to] = cost;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == 1000000000) cout << 0 << ' ';
			else cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}