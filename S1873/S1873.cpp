#include <iostream>
#include <string>
using namespace std;
char a[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void print(int n, int sd, int sx, int sy) {
	char temp = a[sx][sy];
	switch (sd) {
	case 0:
		a[sx][sy] = '>';
		break;
	case 1:
		a[sx][sy] = '<';
		break;
	case 2:
		a[sx][sy] = '^';
		break;
	case 3:
		a[sx][sy] = 'v';
		break;
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << '\n';
	}
	cout << '\n';
	a[sx][sy] = temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case){
		int n, m; cin >> n >> m;
		int sx, sy, sd;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == '<') {
					sx = i, sy = j;
					sd = 1;
				}
				else if (a[i][j] == '>') {
					sx = i, sy = j;
					sd = 0;
				}
				else if (a[i][j] == '^') {
					sx = i, sy = j;
					sd = 2;
				}
				else if (a[i][j] == 'v') {
					sx = i, sy = j;
					sd = 3;
				}
			}
		}
		a[sx][sy] = '.';
		int len; cin >> len;
		string cmd; cin >> cmd;
		for (int i = 0; i < len; ++i) {
			//print(n, sd, sx, sy);
			if (cmd[i] == 'U') {
				sd = 2;
				int nx = sx - 1;
				if (nx >= 0 && nx < n) if (a[nx][sy] == '.')sx = nx;
			}
			else if (cmd[i] == 'D') {
				sd = 3;
				int nx = sx + 1;
				if (nx >= 0 && nx < n) if (a[nx][sy] == '.')sx = nx;
			}
			else if (cmd[i] == 'L') {
				sd = 1;
				int ny = sy - 1;
				if (ny >= 0 && ny < m) if (a[sx][ny] == '.')sy = ny;
			}
			else if (cmd[i] == 'R') {
				sd = 0;
				int ny = sy + 1;
				if (ny >= 0 && ny < m) if (a[sx][ny] == '.')sy = ny;
			}
			else if (cmd[i] == 'S') {
				int nx = sx + dx[sd];
				int ny = sy + dy[sd];
				while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (a[nx][ny] == '#') break;
					else if (a[nx][ny] == '*') {
						a[nx][ny] = '.';
						break;
					}
					nx += dx[sd];
					ny += dy[sd];
				}
			}
		}
		switch (sd) {
		case 0:
			a[sx][sy] = '>';
			break;
		case 1:
			a[sx][sy] = '<';
			break;
		case 2:
			a[sx][sy] = '^';
			break;
		case 3:
			a[sx][sy] = 'v';
			break;
		}
		cout << '#' << test_case << ' ';
		for (int i = 0; i < n; ++i) cout << a[i] << '\n';
	}
}