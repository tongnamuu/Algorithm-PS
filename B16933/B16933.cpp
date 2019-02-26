#include <iostream>
#include <queue>
using namespace std;
struct pos {
	int first, second, day, broken;
};
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int a[1001][1001] = { 0, };
int d[1001][1001][2][11] = { 0, };
int n, m, k;
queue<pos>q;
int bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int day = q.front().day;
		int broken1 = q.front().broken;
		q.pop();
		if (x == n - 1 && y == m - 1) return d[x][y][day][broken1];
		for (int dir = 0; dir < 5; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nday = 1 - day;
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
				if (broken1 < k && d[nx][ny][nday][broken1 + 1] == 0 && a[nx][ny] == 1 && day==0) {
					d[nx][ny][nday][broken1 + 1] = d[x][y][day][broken1] + 1;
					q.push({ nx,ny,nday,broken1 + 1 });
				}
				else if (a[nx][ny] == 0 && d[nx][ny][nday][broken1] == 0) {
					d[nx][ny][nday][broken1] = d[x][y][day][broken1] + 1;
					q.push({ nx,ny,nday,broken1 });
				}
				else if (a[nx][ny] == 1 && d[x][y][nday][broken1] == 0 && day == 1) {
					d[x][y][nday][broken1] = d[x][y][day][broken1] + 1;
					q.push({ nx,ny,nday,broken1 });			
				}
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%1d", &a[i][j]);
	q.push({ 0,0,0,0 });
	d[0][0][0][0] = 1;
	int ans=bfs();
	cout << ans  << '\n';
}