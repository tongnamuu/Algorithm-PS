#include <iostream>
#include <algorithm>
using namespace std;
#define N 100001
int a[10][N];
int d[10][N];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			int temp = 0;
			for (int k = 0; k < m; ++k) {
				if (i != 1 && k == j) temp = a[j][i] / 2;
				else temp = a[j][i];
				d[j][i] = max(d[k][i - 1] + temp, d[j][i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = max(d[i][n], ans);
	}
	cout << ans;
}