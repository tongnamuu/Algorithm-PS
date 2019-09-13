#include <iostream>
using namespace std;
int a[601][601];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, x, y; cin >> n >> m >> x >> y;
	for (int i = 0; i < n + x; ++i) {
		for (int j = 0; j < m + y; ++j) {
			cin >> a[i][j];
			if (i >= x && j >= y) {
				a[i][j] -= a[i - x][j - y];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}