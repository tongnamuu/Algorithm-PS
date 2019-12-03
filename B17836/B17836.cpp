#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[101][101];
int d[101][101][2];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
struct pos {
	int first, second;
	int sword = 0;
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, T;
	cin >> n >> m >> T;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	queue<pos>q;
	q.push({ 0,0,0 });
	d[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int sword = q.front().sword;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny][sword]==0) {
					d[nx][ny][sword] = d[x][y][sword] + 1;
					q.push({ nx,ny,sword });
				}
				else if (a[nx][ny] == 2 && d[nx][ny][sword] == 0) {
					d[nx][ny][1] = d[x][y][sword] + 1;
					q.push({ nx,ny,1 });
				}
				else if (a[nx][ny] == 1 && d[nx][ny][sword]==0) {
					if (sword == 1) {
						d[nx][ny][sword] = d[x][y][sword] + 1;
						q.push({ nx,ny,sword });
					}
				}
			}
		}
	}
	int ans = d[n - 1][m - 1][0];
	if (ans == 0) {
		ans = d[n - 1][m - 1][1];
	}
	else {
		if (d[n - 1][m - 1][1] != 0) {
			ans = min(ans, d[n - 1][m - 1][1]);
		}
	}
	--ans;
	if (ans == -1 || ans > T) cout << "Fail" << '\n';
	else cout << ans << '\n';
}