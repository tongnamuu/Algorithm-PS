#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int a[21][21];
int n;
int tot = 0;
int ssize = 2;
struct nextpos {
	int x = 0;
	int y = 0;
	int cnt;
};
nextpos bfs(nextpos now) {
	int d[21][21] = { 0, };
	bool find = false;
	queue<pair<int, int>>q;
	pair<int, int> hubo[21];
	int pn = 0;
	int mindist = -1;
	q.push({ now.x,now.y });
	d[now.x][now.y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < n && d[nx][ny] == 0) {
				if (a[nx][ny] > ssize) continue;
				if (a[nx][ny] == 0) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
				else if (a[nx][ny] == ssize) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
				else if (a[nx][ny] < ssize) {
					find = true;
					d[nx][ny] = d[x][y] + 1;
					if (mindist == -1 || d[nx][ny] - 1 <= mindist) {
						hubo[pn++] = { nx,ny };
						mindist = d[nx][ny] - 1;
					}
				}
			}
		}
	}
	if (!find) {
		return { -1,-1,0 };
	}
	sort(hubo, hubo + pn);
	tot += (d[hubo[0].first][hubo[0].second] - 1);
	if (now.cnt + 1 == ssize) {
		++ssize;
		a[hubo[0].first][hubo[0].second] = 0;
		return { hubo[0].first,hubo[0].second, 0 };
	}
	else {
		a[hubo[0].first][hubo[0].second] = 0;
		return { hubo[0].first,hubo[0].second, now.cnt + 1 };
	}
}
int main() {
	cin >> n;
	int startx, starty;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				startx = i;
				starty = j;
				a[i][j] = 0;
			}
		}
	}
	nextpos p = { startx,starty,0 };
	while (p.x != -1 && p.y != -1) {
		p = bfs(p);
	}
	cout << tot << '\n';
}