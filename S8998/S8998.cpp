#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int>a[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].second >> a[i].first;
		}
		sort(a, a + n);
		int ans = a[n - 1].first;
		for (int i = n - 1; i >= 1; --i) {
			if (ans - a[i].second > a[i - 1].first) {
				ans = a[i - 1].first;
			}
			else ans -= a[i].second;
		}
		ans -= a[0].second;
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}