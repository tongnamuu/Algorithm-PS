#include <iostream>
using namespace std;
char a[201][201];
char b[51][51];
int n, m;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		for (int j = 0; j < m; ++j) {
			a[i][j] = b[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[2 * n - 1 - i][2 * m - 1 - j] = b[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][2 * m - 1 - j] = b[i][j];
		}
	}
	for (int i = n; i < 2 * n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = b[2 * n - 1 - i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	if (a[x - 1][y - 1] == '.')a[x - 1][y - 1] = '#';
	else a[x - 1][y - 1] = '.';
	for (int i = 0; i < 2 * n; ++i) cout << a[i] << '\n';
}