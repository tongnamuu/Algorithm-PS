#include <iostream>
using namespace std;
char a[3001][3001];
int height[3001];
int min(int x, int y) { return x > y ? y : x; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'X') {
				height[j] = i;
			}
		}
	}
	int dist = 2147483647;
	for (int x = 0; x < m; ++x) {
		if (height[x] == 0) continue;
		int start = height[x];
		++start;
		while (a[start][x] == '.') {
			++start;
		}
		height[x] = start - height[x] - 1;
		dist = min(dist, height[x]);
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'X') {
				a[i + dist][j] = 'X';
				a[i][j] = '.';
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << '\n';
	}
}