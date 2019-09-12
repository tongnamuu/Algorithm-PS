#include <iostream>
using namespace std;
char a[501][501];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.') a[i][j] = 'D';
		}
	}
	int safe = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'S') {
				for (int dir = 0; dir < 4; ++dir) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
						if (a[nx][ny] == 'W') {
							safe = 0;
							i = n, j = m;
							break;
						}
					}
				}
			}
		}
	}
	cout << safe << '\n';
	if(safe) for (int i = 0; i < n; ++i)cout << a[i] << '\n';
}