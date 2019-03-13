#include <iostream>
#include <memory.h>
using namespace std;
int a[33][33];
long long d[33][33][3];
int n;
long long ans;
long long go(int x, int y, int direction) {
	if (d[x][y][direction] != -1) return d[x][y][direction];
	long long cnt = 0;
	if (direction == 0) {
		if (x == n - 1 && y == n - 1) 	return 1;
		if (y + 1 < n && a[x][y + 1] == 0) 	cnt += go(x, y + 1, 0);
		if (x + 1 < n && y + 1 < n && a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) cnt += go(x + 1, y + 1, 1);
	}
	else if (direction == 1) {
		if (x == n - 1 && y == n - 1) return 1;
		if (y + 1 < n && a[x][y + 1] == 0) 	cnt += go(x, y + 1, 0);
		if (x + 1 < n && a[x + 1][y] == 0) 	cnt += go(x + 1, y, 2);	
		if (x + 1 < n && y + 1 < n && a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) cnt += go(x + 1, y + 1, 1);	
	}
	else if (direction == 2) {
		if (x == n - 1 && y == n - 1) return 1;
		if (x + 1 < n && a[x + 1][y] == 0) cnt += go(x + 1, y, 2);
		if (x + 1 < n && y + 1 < n && a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) cnt += go(x + 1, y + 1, 1);
	}
	d[x][y][direction] = cnt;
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	if (a[0][2] == 0) ans += go(0, 2, 0);
	if (a[0][1] == 0 && a[0][2] == 0 && a[1][2] == 0 && a[1][1] == 0) ans += go(1, 2, 1);
	cout << ans << '\n';
}