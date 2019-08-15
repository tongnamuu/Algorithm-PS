#include <iostream>
using namespace std;
long long d[1 << 10][101][10];
const long long mod = 1000000000LL;
int main() {
	int n; cin >> n;
	for (int i = 1; i < 10; ++i) {
		d[1 << i][1][i] = 1LL;
	}
	for (int i = 1; i + 1 <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int x = 0; x < (1 << 10); ++x) {
				if ((x&(1 << j)) == 0) continue;
				if (d[x][i][j] == 0) continue;
				if (j - 1 >= 0) {
					d[x | (1 << (j - 1))][i + 1][j - 1] += d[x][i][j];
					d[x | (1 << (j - 1))][i + 1][j - 1] %= mod;
				}
				if (j + 1 <= 9) {
					d[x | (1 << (j + 1))][i + 1][j + 1] += d[x][i][j];
					d[x | (1 << (j + 1))][i + 1][j + 1] %= mod;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; ++i) {
		ans += d[(1 << 10) - 1][n][i];
		ans %= mod;
	}
	cout << ans << '\n';
}