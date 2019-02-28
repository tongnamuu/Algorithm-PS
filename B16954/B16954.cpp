#include <iostream>
#include <queue>
using namespace std;
char a[10][9];
bool check[10][9];
int dx[] = { 0, -1,0,1,-1,1,-1,0,1 };
int dy[] = { 0, -1,-1,-1,0,0,1,1,1 };
bool go = false;
int T = 8;
int height = -1;
queue<pair<int, int>>q;
void movewall() {
	for (int i = 7; i >= height; --i) {
		for (int j = 0; j < 8; ++j) {
			if (a[i][j] == '#') {
				a[i + 1][j] = '#';
				a[i][j] = '.';
			}
		}
	}
	height++;
}
void bfs() {
	int cnt = q.size();
	while (cnt--) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x < height) {
			go = true; return;
		}
		if (a[x][y] == '#') continue;
		for (int dir = 0; dir < 9; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && a[nx][ny] == '.') {
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 8; ++i) {
		cin >> a[i];
		for (int j = 0; j < 8; ++j) {
			if (a[i][j] == '#' && height == -1) height = i;
		}
	}
	if (height == -1) cout << 1 << '\n';
	else {
		q.push({ 7,0 });
		while (!go && height <= 8) {
			bfs();
			movewall();
		}
		cout << go ? 1 : 0 << '\n';
	}
}