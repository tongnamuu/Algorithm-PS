#include <iostream>
using namespace std;
char a[51][51];
char b[51][51];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i + 2 < n; ++i) {
		for (int j = 0; j + 2 < m; ++j) {
			if (a[i][j] != b[i][j]) {
				++ans;
				for (int ii = i; ii < i + 3; ++ii) {
					for (int jj = j; jj < j + 3; ++jj) {
						a[ii][jj] = ((a[ii][jj] - '0') ^ 1) + '0';
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != b[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << ans << '\n';
}