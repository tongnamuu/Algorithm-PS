#include <iostream>
using namespace std;
char a[51][51];
int max(int a, int b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	int size = n < m ? n : m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; ; ++k) {
				if (i + k >= n || j + k >= m) break;
				if (a[i][j] == a[i + k][j] && a[i][j] == a[i][j + k] && a[i][j] == a[i + k][j + k]) {
					ans = max(ans, k + 1);
				}
			}
		}
	}
	cout << ans * ans << '\n';
}