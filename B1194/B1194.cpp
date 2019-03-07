#include <iostream>
#include <queue>
using namespace std;
int n, m;
char a[51][51];
int d[51][51][1 << 6];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int sx, sy;
struct state {
	int first, second, key;
};
int bfs() {
	queue<state>q;
	q.push({ sx,sy, 0 });
	d[sx][sy][0] = 1;
	int len = -1;
	while (!q.empty()) {
		int k = q.size();
		len++;
		while (k--) {
			int x = q.front().first;
			int y = q.front().second;
			int now = q.front().key;
			if (a[x][y] == '1') return len;		
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m ) {
					if (a[nx][ny] == '#') continue;//º®
					else if (a[nx][ny] >= 'a'&&a[nx][ny] <= 'f') {//¿­¼è
						int key= now | (1 << (a[nx][ny] - 'a'));
						if (d[nx][ny][key] == 0) {
							q.push({ nx,ny,key });
							d[nx][ny][key] = d[x][y][now] + 1;
						}
					}
					else if (a[nx][ny] == '.'|| a[nx][ny] == '1') {//ºó°÷
						if (d[nx][ny][now] == 0) {
							q.push({ nx,ny,now });
							d[nx][ny][now] = d[x][y][now] + 1;
						}
					}
					else if (a[nx][ny] >= 'A'&&a[nx][ny] <= 'F') {//¹®
						int pos = (1 << (a[nx][ny] - 'A'));
						if (now&pos) {
							if (d[nx][ny][now] == 0) {
								q.push({ nx,ny,now });
								d[nx][ny][now] = d[x][y][now] + 1;
							}
						}
					}

				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m; 
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '0') {
				sx = i, sy = j;
				a[i][j] = '.';
			}
		}
	}
	cout << bfs() << '\n';
}