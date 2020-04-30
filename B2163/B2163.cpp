#include <iostream>
#include <algorithm>
using namespace std;
int d[301][301];
int n, m;
int go(int x, int y) {
	if (x == 1 && y == 1) return 0;
	int& ret = d[x][y];
	if (ret != 1000000000) return ret;
	for (int i = 1; i < x; ++i) {
		ret = min(ret, go(i, y) + go(x - i, y) + 1);
	}
	for (int i = 1; i < y; ++i) {
		ret = min(ret, go(x, i) + go(x, y - i) + 1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			d[i][j] = 1000000000;
		}
	}
	cout << go(n, m);
}