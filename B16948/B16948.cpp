#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
const int dx[] = { -2,-2,0,0,2,2 };
const int dy[] = { -1,1,-2,2,-1,1 };
int d[201][201];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	memset(d, -1, sizeof(d));
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	d[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 6; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n&&d[nx][ny] == -1) {
				q.push({ nx,ny });
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}
	cout << d[ex][ey] << '\n';
}