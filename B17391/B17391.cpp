#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[301][301];
int d[301][301];
const int dx[] = { 1,0 };
const int dy[] = { 0,1 };
int n, m;
int go(int x, int y) {
	int& ret = d[x][y];
	if (ret != -1) return ret;
	if (x == n && y == m) return ret = 0;
	ret = 1;
	int r = a[x][y];
	int temp = 2147483647;
	for (int k = 1; k <= r; ++k) {
		if (x + k > n) break;
		temp = min(go(x + k, y), temp);
	}
	for (int k = 1; k <= r; ++k) {
		if (y + k > m) break;
		temp = min(go(x, y + k), temp);
	}
	return ret += temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}
	cout << go(1, 1);
}