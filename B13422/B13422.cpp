#include <iostream>
using namespace std;
int n, m, k;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) cin >> a[i];
		long long sum = 0;
		for (int i = 0; i < m; ++i) sum += a[i];
		int ans = sum < k ? 1 : 0;
		for (int i = 0; i < n; ++i) {
			sum -= a[i];
			sum += a[(m + i) % n];
			if ((m + i) % n == m - 1) break;
			if ((m + i) % n == i) break;
			if (sum < k) ++ans;
		}
		cout << ans << '\n';
	}
}