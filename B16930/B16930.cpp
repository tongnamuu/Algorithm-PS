#include <iostream>
#include <queue>
using namespace std;
char a[1001][1001];
int d[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	sx -= 1, sy -= 1, ex -= 1, ey -= 1;
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	d[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == ex && y == ey) break;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int cnt = k;
			while (nx >= 0 && nx < n&&ny >= 0 && ny < m&&cnt--){
				if (a[nx][ny] == '#') break;
				if (a[nx][ny] == '.'&&d[nx][ny] == 0) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
				nx += dx[dir];
				ny += dy[dir];
			}
		}
	}
	cout << d[ex][ey] - 1 << '\n';
}