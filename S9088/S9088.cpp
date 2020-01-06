#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int index1 = upper_bound(a, a + n, a[i] + k) - a;
			ans = max(ans, index1 - i);
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}