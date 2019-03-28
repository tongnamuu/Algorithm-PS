#include <iostream>
using namespace std;
int a[20][20];
bool check[4][20][20];
const int dx[] = { 1,1,0 ,1 };
const int dy[] = { 0,1,1 ,-1 };
const int n = 19;
bool go(int x, int y, int dir, int mark) {
	int cnt = 1;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	check[dir][x][y] = true;
	while (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == mark && !check[dir][nx][ny]) {
		check[dir][nx][ny] = true;
		++cnt;
		nx += dx[dir];
		ny += dy[dir];
	}
	return cnt == 5;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 19; ++i) for (int j = 1; j <= 19; ++j) cin >> a[i][j];
	for (int i = 1; i <= 19; ++i) {
		for (int j = 1; j <= 19; ++j) {
			if (a[i][j] > 0) {
				for (int dir = 0; dir < 4; ++dir) {
					if (!check[dir][i][j]) {
						if (go(i, j, dir, a[i][j])) {
							cout << a[i][j] << '\n';
							if (dir == 3) cout << i + 4 << ' ' << j - 4 << '\n';
							else cout << i << ' ' << j << '\n';
							return 0;
						}
					}
				}
			}
		}
	}
	cout << 0 << '\n';
}