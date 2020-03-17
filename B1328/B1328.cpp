#include <iostream>
using namespace std;
#define MOD 1000000007
long long d[101][101][101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, l, r; cin >> n >> l >> r;
	d[1][1][1] = 1LL;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= l; ++j) {
			for (int k = 1; k <= r; ++k) {
				d[i][j][k] = d[i - 1][j - 1][k] + d[i - 1][j][k - 1] + d[i - 1][j][k] * (i - 2);
				d[i][j][k] %= MOD;
			}
		}
	}
	cout << d[n][l][r];
}