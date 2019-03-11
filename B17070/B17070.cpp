#include <iostream>
using namespace std;
int a[16][16];
int n;
int ans;
void go(int x, int y, int direction) {
	if (x == n - 1 && y == n - 1) {
		++ans;
		return;
	}
	if (direction == 0) {
		if (y + 1 < n && a[x][y + 1] == 0) {
			go(x, y + 1, 0);
		}
		if (x + 1 < n && y + 1 < n && a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) {
			go(x + 1, y + 1, 1);
		}
	}
	else if (direction == 1) {
		if (y + 1 < n && a[x][y + 1] == 0) {
			go(x, y + 1, 0);
		}
		if (x + 1 < n && a[x+1][y] == 0) {
			go(x+1, y, 2);
		}
		if (x + 1 < n && y + 1 < n && a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) {
			go(x + 1, y + 1, 1);
		}
	}
	else if (direction == 2) {
		if (x + 1 < n && a[x + 1][y] == 0) {
			go(x + 1, y, 2);
		}
		if (x + 1 < n && y + 1 < n && a[x][y] == 0 && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) {
			go(x + 1, y + 1, 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	if (a[0][2] == 0) go(0, 2, 0);
	if (a[0][1] == 0 && a[0][2] == 0 && a[1][2] == 0 && a[1][1] == 0) go(1, 2, 1);
	cout << ans << '\n';
}