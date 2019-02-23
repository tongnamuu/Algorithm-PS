#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int d[101] = { 0, };
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i%j == 0) d[i]++;
		}
	}
	int T; cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (d[i] & 1) ans++;
		}
		cout << ans << '\n';
	}
}