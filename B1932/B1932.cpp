#include <iostream>
#include <memory.h>
using namespace std;
int a[501][501];
int d[501][501];
int n;
int max(int a, int b) { return a > b ? a : b; }
int go(int x, int y) {
	if (x == n - 1) {
		return d[x][y]=a[x][y];
	}
	if (d[x][y] != -1) return d[x][y];
	d[x][y] = a[x][y] + max(go(x + 1, y), go(x + 1, y + 1));
	return d[x][y];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> a[i][j];
		}
	}
	cout << go(0, 0) << '\n';
}