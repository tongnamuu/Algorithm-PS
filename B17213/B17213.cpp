#include <iostream>
using namespace std;
int d[31][31];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		d[i][0] = d[i][i] = 1;
	}
	for (int i = 2; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = d[i - 1][j];
			if (j >= 1) d[i][j] += d[i - 1][j - 1];
		}
	}
	cout << d[m - 1][n - 1];
}