#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int n;
long long calc(long long num) {
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (num / a[i]);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int m; cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		long long begin = 0;
		long long end = (long long)a[n - 1] * m + 1;
		long long ans = end;
		while (begin < end) {
			long long mid = (begin + end) / 2;
			if (calc(mid) >= m) {
				if (ans > mid) ans = mid;
				end = mid;
			}
			else begin = mid + 1;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}