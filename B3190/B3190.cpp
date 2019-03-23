#include <iostream>
using namespace std;
int a[101][101] = { 0, };
int d[101][101] = { 0, };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main() {
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	d[0][0] = 1;
	int apple;
	cin >> apple;
	while (apple--) {
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = 1;
	}
	int T;
	cin >> T;
	int ans = 0;
	int len = 1;
	int x = 0, y = 0;
	int nowd = 0;
	for (int k = 0; k <= T; ++k) {
		int time = n * n - 1;
		char cmd;
		if (k < T) {
			cin >> time >> cmd;
		}
		while (ans < time) {
			++ans;
			int nx = x + dx[nowd];
			int ny = y + dy[nowd];
			if (!(nx >= 0 && nx < n&&ny >= 0 && ny < n)) {
				cout << ans << '\n';
				return 0;
			}
			if (a[nx][ny] == 1) {
				d[nx][ny] = d[x][y] + 1;
				a[nx][ny] = 0;
				++len;
				x = nx;
				y = ny;
			}
			else if (a[nx][ny] == 0 && d[nx][ny] == 0) {
				d[nx][ny] = d[x][y] + 1;
				x = nx;
				y = ny;
			}
			else if (a[nx][ny] == 0 && d[nx][ny] != 0) {
				if (d[nx][ny] + len > d[x][y]) {
					cout << ans << '\n';
					return 0;
				}
				else {
					d[nx][ny] = d[x][y] + 1;
					x = nx;
					y = ny;
				}
			}
		}
		if (cmd == 'D') nowd = (nowd + 1) % 4;
		else if (cmd == 'L') nowd = (nowd + 3) % 4;

	}
}