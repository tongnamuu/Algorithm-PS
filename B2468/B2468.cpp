#include <iostream>
using namespace std;
int a[101][101];
bool check[100][100] = { false, };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n;
void go(int x, int y, int t) {
	check[x][y] = true;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			if (a[nx][ny] <= t && !check[nx][ny]) go(nx, ny, t);
		}
	}
}
void go2(int x, int y) {
	check[x][y] = true;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			if (!check[nx][ny]) go2(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	int ans = 0;
	for (int t = 99; t >=0; --t) {
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) check[i][j] = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!check[i][j] && a[i][j] <= t) go(i, j, t);
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!check[i][j]) {
					go2(i, j);
					++cnt;
				}
			}
		}
		if (cnt > ans) ans = cnt;
	}
	cout << ans << '\n';
}