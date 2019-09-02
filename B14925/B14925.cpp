#include <iostream>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int min(int x, int y) { return x > y ? y : x; }
int min3(int x, int y, int z) {
	return min(min(x, y), z);
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] > 0) continue;
			d[i][j] = min3(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + 1;
			if (d[i][j] > ans) ans = d[i][j];
		}
	}
	cout << ans << '\n';
}