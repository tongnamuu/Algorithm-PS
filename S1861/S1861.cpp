#include <iostream>
#include <queue>
using namespace std;
int a[1001][1001];
int d[1001][1001] = { 0, };
int p[1001 * 1001 + 1];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int go(int sx, int sy) {
	if (p[sx * 1001 + sy]) return p[sx * 1001 + sy];
	int x = -1, y = -1;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = sx + dx[dir];
		int ny = sy + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			if (a[nx][ny] == a[sx][sy] - 1) x = nx, y = ny;
		}
	}
	if (x == -1 && y == -1) return p[sx * 1001 + sy] = sx * 1001 + sy;
	else return p[sx * 1001 + sy] = go(x, y);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				d[i][j] = 0;
				p[i * 1001 + j] = 0;
			}
		}
		int ans = 2147483647;
		int max = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) go(i, j);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int temp = p[i * 1001 + j];
				d[temp / 1001][temp % 1001]++;
			}
		}
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)	if (d[i][j] >= max) max = d[i][j];
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (d[i][j] == max && ans > a[i][j]) ans = a[i][j]; 
		cout << '#' << test_case << ' ' << ans << ' ' << max << '\n';
	}
}