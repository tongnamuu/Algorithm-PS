#include <iostream>
using namespace std;
int map[2001][2001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b, c, d;
	for (int i = 0; i < 2; ++i) {
		cin >> a >> b >> c >> d;
		a += 1000, b += 1000, c += 1000, d += 1000;
		for (int j = a; j < c; ++j) {
			for (int k = b; k < d; ++k) {
				map[j][k]++;
			}
		}
	}
	cin >> a >> b >> c >> d;
	a += 1000, b += 1000, c += 1000, d += 1000;
	for (int j = a; j < c; ++j) {
		for (int k = b; k < d; ++k) {
			map[j][k] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 2000; ++i) {
		for (int j = 0; j <= 2000; ++j) {
			if (map[i][j] > 0) ++ans;
		}
	}
	cout << ans << '\n';
}