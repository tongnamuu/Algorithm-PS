#include <iostream>
#include <queue>
using namespace std;
int a[101][101];
int d[101][101];
int bridge[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n;
int min(int a, int b) {
	if (a > b) return b;
	else return a;
}
void bfs(int sx, int sy, int mark) {
	d[sx][sy] = mark;
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
				if (d[nx][ny] == 0 && a[nx][ny] == 1) {
					d[nx][ny] = mark;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int mark = 1, cnt = 1; cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (a[i][j] == 1 && d[i][j]==0) bfs(i, j, mark++);
	queue<pair<int, int >> q;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (d[i][j]>0) { bridge[i][j] = 1, q.push({ i,j }); }
	int ans = 2147483647;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
				if (d[x][y] == d[nx][ny]) continue;
				if (d[nx][ny] == 0) {
					q.push({ nx,ny });
					bridge[nx][ny] = bridge[x][y] + 1;
					d[nx][ny] = d[x][y];
				}
				else {
					ans = min(bridge[nx][ny] + bridge[x][y], ans);
				}
			}
		}
	}
	cout << ans - 2 << '\n';
}