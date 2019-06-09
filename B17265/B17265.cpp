#include <iostream>
using namespace std;
char a[6][6];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int n;
char s[12];
int maxn = -2147483647, minn = 2147483647;
void cal(int index) {
	int num = s[0] - '0';
	for (int i = 1; s[i + 1]; i += 2) {
		if (s[i] == '+') {
			num += (s[i + 1] - '0');
		}
		else if (s[i] == '-') {
			num -= (s[i + 1] - '0');
		}
		else if (s[i] == '*') {
			num *= (s[i + 1] - '0');
		}
	}
	if (num > maxn) maxn = num;
	if (num < minn) minn = num;
}
void go(int x, int y, int index) {
	s[index] = a[x][y];
	if (x == n - 1 && y == n - 1) {
		cal(index);
		return;
	}
	for (int dir = 0; dir < 2; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			go(nx, ny, index + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	go(0, 0, 0);
	cout << maxn << ' ' << minn << '\n';
}