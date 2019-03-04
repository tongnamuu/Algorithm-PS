#include <iostream>
#include <queue>
using namespace std;
char a[9][9];
char map[51][51];
int n, m;
int min(int a, int b) {
	if (a > b) return b;
	else return a;
}
int checkw() {
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((i + j) & 1) {
				if (a[i][j] == 'W') cnt++;
			}
			else {
				if (a[i][j] == 'B') cnt++;
			}
		}
	}
	return cnt;
}
int checkb() {
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((i + j) & 1) {
				if (a[i][j] == 'B') cnt++;
			}
			else {
				if (a[i][j] == 'W') cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m; for (int i = 0; i < n; ++i) cin >> map[i];
	int ans = 2147483647;
	for (int i = 0; i + 7 < n; ++i) {
		for (int j = 0; j + 7 < m; ++j) {
			for (int x = 0; x < 8; ++x) {
				for (int y = 0; y < 8; ++y) {
					a[x][y] = map[i + x][j + y];
				}
			}
			ans = min(ans, checkb());
			ans = min(ans, checkw());
		}
	}
	cout << ans << '\n';
}