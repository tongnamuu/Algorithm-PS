#include <iostream>
#include <queue>
using namespace std;
int a[101][101][101];
int d[101][101][101];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
struct pos {
	int z, x, y;
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, h;
	cin >> m >> n >> h;
	queue<pos>q;
	int ans = 0, cnt = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> a[i][j][k];
				if (a[i][j][k] == 1) {
					q.push({ i,j,k });
					d[i][j][k] = 1;
					++cnt, ++ans;
				}
				else if (a[i][j][k] == 0) ++ans;
			}
		}
	}
	int day = 0;
	while (!q.empty()) {
		int k = q.size();
		++day;
		while (k--) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			for (int dir = 0; dir < 6; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nz = z + dz[dir];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&nz >= 0 && nz < h) {
					if (a[nz][nx][ny] == 0 && d[nz][nx][ny] == 0) {
						q.push({ nz,nx,ny });
						d[nz][nx][ny] = d[z][x][y] + 1;
						++cnt;
					}
				}
			}
		}
	}
	if(ans==cnt) cout << day - 1 << '\n';
	else cout << -1 << '\n';
}