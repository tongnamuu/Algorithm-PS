#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
char a[51][51];
int gnext[51][51];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int d[51][51];
struct Edge {
	int cost, x, y;
	bool operator<(const Edge& a) const {
		return this->cost > a.cost;
	}
};
bool range(int n, int m, int x, int y) { return x >= 0 && x < n&&y >= 0 && y < m; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int sx, sy, ex, ey;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'g') {
				gnext[i][j] = 2501;
				for (int dir = 0; dir < 4; ++dir) {
					int x = i + dx[dir], y = j + dy[dir];
					if (range(n, m, x, y))
						if (gnext[x][y] == 0) gnext[x][y] = 1;
				}
			}
			else if (a[i][j] == 'S') {
				a[i][j] = '.';
				sx = i, sy = j;
			}
			else if (a[i][j] == 'F') {
				a[i][j] = '.';
				ex = i, ey = j;
			}
		}
	}
	gnext[sx][sy] = 0, gnext[ex][ey] = 0;
	memset(d, 0x3f, sizeof(d));
	priority_queue<Edge>q;
	q.push({ 0,sx,sy });
	d[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int c = q.top().cost;
		q.pop();
		if (d[x][y] < c) continue;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (!range(n, m, nx, ny)) continue;
			if (d[nx][ny] > d[x][y] + gnext[nx][ny]) {
				d[nx][ny] = d[x][y] + gnext[nx][ny];
				q.push({ d[nx][ny],nx,ny });
			}
		}
	}
	cout << d[ex][ey] / 2501 << ' ' << d[ex][ey] % 2501 << '\n';
}