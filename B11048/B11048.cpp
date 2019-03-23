#include <iostream>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int max(const int &a, const int &b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			d[i][j] = max(d[i - 1][j], max(d[i - 1][j - 1], d[i][j - 1])) + a[i][j];
		}
	}
	cout << d[n][m] << '\n';
}