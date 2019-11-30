#include <iostream>
using namespace std;
long long d[65][10];
void solve() {
	for (int i = 0; i < 10; ++i) {
		d[1][i] = 1LL;
	}
	for (int i = 1; i < 64; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k) {
				d[i + 1][j] += d[i][k];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	solve();
	while (T--) {
		int n; cin >> n;
		long long ans = 0LL;
		for (int i = 0; i < 10; ++i) {
			ans += d[n][i];
		}
		cout << ans << '\n';
	}
}