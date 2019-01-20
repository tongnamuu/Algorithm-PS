#include <iostream>
#include <queue>
using namespace std;
int n, m;
int a[1001][1001];
int d[1001][1001][4][2];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
struct state {
	int first;
	int second;
	int direction;
	int smell;
};
bool rangecheck(int x, int y, int smell) {
	if (!(x >= 0 && x < n && y >= 0 && y < m)) return false;
	if (a[x][y] == 0) return false;
	if (a[x][y] == 3) {
		if (smell) return true;
		else return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	queue<state>q;
	state now = { 0,0,0,0 };
	d[0][0][0][0] = 1;
	q.push(now);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int nowd = q.front().direction;
		int orange = q.front().smell;
		q.pop();
		if (a[x][y] == 4) {
			int nx = x + dx[nowd];
			int ny = y + dy[nowd];
			if (rangecheck(nx, ny, 0)) {
				q.push({ nx,ny,nowd,0 });
				d[nx][ny][nowd][0] = d[x][y][nowd][orange] + 1;
				continue;
			}
		}
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int neworange;
			if (!(x >= 0 && x < n && y >= 0 && y < m)) continue;
			if (a[nx][ny] == 2) neworange = 1;
			else if (a[nx][ny] == 4) neworange = 0;
			else neworange = orange;
			if (rangecheck(nx, ny, neworange)) {
				if (d[nx][ny][dir][neworange]) continue;
				d[nx][ny][dir][neworange] = d[x][y][nowd][orange] + 1;
				q.push({ nx,ny,dir,neworange });
			}
		}
	}
	int ans = 2147483647;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (d[n - 1][m - 1][i][j]) {
				if (ans > d[n - 1][m - 1][i][j])
					ans = d[n - 1][m - 1][i][j];
			}
		}
	}
	if (ans == 2147483647) cout << -1 << '\n';
	else cout << ans-1 << '\n';
}