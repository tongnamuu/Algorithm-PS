#include <iostream>
using namespace std;
int a[2001][2001];
bool check[2001][2001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = 2147483647;
	int x = 1000, y = 1000;
	a[x][y] = 0;
	int time = 1;
	check[x][y] = true;
	char ch;
	for (int i = 0, S, j; i < n; ++i) {
		cin >> ch >> S;
		if (ch == 'N') {
			for (j = 0; j < S; ++j) {
				--x;
				if (check[x][y]) {
					if (time - a[x][y] < ans) {
						ans = time - a[x][y];
					}
				}
				check[x][y] = true;
				a[x][y] = time;
				++time;
			}
		}
		else if (ch == 'S') {
			for (j = 0; j < S; ++j) {
				++x;
				if (check[x][y]) {
					if (time - a[x][y] < ans) {
						ans = time - a[x][y];
					}
				}
				check[x][y] = true;
				a[x][y] = time;
				++time;
			}
		}
		else if (ch == 'E') {
			for (j = 0; j < S; ++j) {
				++y;
				if (check[x][y]) {
					if (time - a[x][y] < ans) {
						ans = time - a[x][y];
					}
				}
				check[x][y] = true;
				a[x][y] = time;
				++time;
			}
		}
		else if (ch == 'W') {
			for (j = 0; j < S; ++j) {
				--y;
				if (check[x][y]) {
					if (time - a[x][y] < ans) {
						ans = time - a[x][y];
					}
				}
				check[x][y] = true;
				a[x][y] = time;
				++time;
			}
		}
	}
	if (ans == 2147483647) ans = -1;
	cout << ans << '\n';
}