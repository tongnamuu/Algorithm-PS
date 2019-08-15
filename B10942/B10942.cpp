#include <iostream>
#include <string>
using namespace std;
int a[2001];
int d[2001][2001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i + 1]) d[i][i + 1] = 1;
	}
	for (int len = 3; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			if (d[i + 1][j - 1] == 1 && a[i] == a[j]) d[i][j] = 1;
		}
	}
	int m; cin >> m;
	while (m--) {
		int x, y; cin >> x >> y; cout << d[x][y] << '\n';
	}
}