#include <iostream>
using namespace std;
int a[11][11] = { 0, };
int paper[6] = { 0,5,5,5,5,5 };
int ans;
int getsum(int x1, int y1, int x2, int y2) {
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			if (a[i][j] == 0) return 0;
		}
	}
	return 1;
}
void solve(int pos, int curCnt) {
	if (pos == 100) {
		for (int i = 1; i <= 10; ++i) {
			for (int j = 1; j <= 10; ++j) {
				if (a[i][j] == 1) return;
			}
		}
		if (ans > curCnt) ans = curCnt;
		return;
	}
	int x = pos / 10 + 1;
	int y = pos % 10 + 1;
	if (a[x][y] == 0)  solve(pos + 1, curCnt);
	else {
		for (int size = 1; size <= 5; ++size) {
			if (paper[size] > 0 && x + size - 1 <= 10 && y + size - 1 <= 10) {
				if (getsum(x, y, x + size - 1, y + size - 1) == 1) {
					--paper[size];
					for (int i = x; i < x + size; ++i) {
						for (int j = y; j < y + size; ++j) {
							a[i][j] = 0;
						}
					}
					solve(pos + 1, curCnt + 1);
					++paper[size];
					for (int i = x; i < x + size; ++i) {
						for (int j = y; j < y + size; ++j) {
							a[i][j] = 1;
						}
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			cin >> a[i][j];
		}
	}
	ans = 2147483647;
	solve(0, 0);
	if (ans == 2147483647) cout << -1 << '\n';
	else cout << ans << '\n';
}