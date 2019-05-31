#include <iostream>
using namespace std;
char a[51][51];
int n, m;
int ans;
void solve(char first, char second) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == first) {
				if (i + 1 < n&&i + 2 < n) {
					if (a[i + 1][j] == second && a[i + 2][j] == second) ++cnt;
				}
				if (i - 1 >= 0 && i - 2 >= 0) {
					if (a[i - 1][j] == second && a[i - 2][j] == second) ++cnt;
				}
				if (j + 1 < m&&j + 2 < m) {
					if (a[i][j + 1] == second && a[i][j + 2] == second) ++cnt;
				}
				if (j - 1 >= 0 && j - 2 >= 0) {
					if (a[i][j - 1] == second && a[i][j - 2] == second) ++cnt;
				}
				if (i + 1 < n&&i + 2 < n&&j + 1 < m&&j + 2 < m) {
					if (a[i + 1][j + 1] == second && a[i + 2][j + 2] == second) ++cnt;
				}
				if (i + 1 < n&&i + 2 < n&&j - 1 >= 0 && j - 2 >= 0) {
					if (a[i + 1][j - 1] == second && a[i + 2][j - 2] == second) ++cnt;
				}
				if (i - 1 >= 0 && i - 2 >= 0 && j + 1 < m&&j + 2 < m) {
					if (a[i - 1][j + 1] == second && a[i - 2][j + 2] == second) ++cnt;
				}
				if (i - 1 >= 0 && i - 2 >= 0 && j - 1 >= 0 && j - 2 >= 0) {
					if (a[i - 1][j - 1] == second && a[i - 2][j - 2] == second) ++cnt;
				}
			}
		}
	}
	if (cnt > ans) {
		ans = cnt;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (char s = 'A'; s <= 'Z'; ++s) {
		for (char b = 'A'; b <= 'Z'; ++b) {
			if (s == 'M') continue;
			if (b == 'O') continue;
			if (s == b) continue;
			solve(s, b);
		}
	}
	cout << ans << '\n';
}