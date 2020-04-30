#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][31][2];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, x; cin >> n >> m >> x;
	x--;d[1][x][x] = 1;
	for (int i = 2; i <= n; ++i) {
		cin >> x; x--;
		int r = min(i, m);
		for (int j = 0; j <= r; ++j) {
			d[i][j][x] = d[i - 1][j][x] + 1;
			if (j) d[i][j][x] = max(d[i - 1][j - 1][x ^ 1] + 1, d[i][j][x]);
			d[i][j][x ^ 1] = d[i - 1][j][x ^ 1];
			if (j) d[i][j][x ^ 1] = max(d[i - 1][j - 1][x], d[i][j][x ^ 1]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; ++i) {
		ans = max({ans, d[n][i][0], d[n][i][1]});
	}
	cout << ans;
}