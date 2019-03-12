#include <iostream>
#include <queue>
using namespace std;
char a[31][31][31];
int d[31][31][31];
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
struct pos {
	int z, x, y;
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, h;
	while (true) {
		cin >> h >> n >> m;
		int ex, ey, ez;
		if (h == 0 && n == 0 && m == 0) break;
		queue<pos>q;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				for (int k = 0; k < m; ++k) {
					d[i][j][k] = 0;
					if (a[i][j][k] == 'S') {
						q.push({ i,j,k });
						d[i][j][k] = 1;
						a[i][j][k] = '.';
					}
					else if (a[i][j][k] == 'E') {
						ez = i;
						ex = j;
						ey = k;
						a[i][j][k] = '.';
					}
				}
			}
		}
		while (!q.empty()) {
			pos now = q.front(); q.pop();
			for (int dir = 0; dir < 6; ++dir) {
				int nx = now.x + dx[dir];
				int ny = now.y + dy[dir];
				int nz = now.z + dz[dir];
				if (nz >= 0 && nz < h&&nx >= 0 && nx < n&&ny >= 0 && ny < m) {
					if (a[nz][nx][ny] == '.'&&d[nz][nx][ny] == 0) {
						d[nz][nx][ny] = d[now.z][now.x][now.y] + 1;
						q.push({ nz,nx,ny });
					}
				}
			}
		}
		if (d[ez][ex][ey] == 0) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << d[ez][ex][ey] - 1 << ' ' << "minute(s)." << '\n';
	}
}