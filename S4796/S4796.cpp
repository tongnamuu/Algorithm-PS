#include <iostream>
using namespace std;
int a[50001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		int upcnt = 0, downcnt = 0;
		int ans = 0;
		int temp = a[1];
		if (a[0] < temp) ++upcnt;
		int i = 2;
		while (i < n) {
			while (i<n&&a[i] > temp) {
				temp = a[i];
				++upcnt;
				++i;
			}
			if (i == n) break;
			while (i < n&&a[i] < temp) {
				temp = a[i];
				++downcnt;
				++i;
			}
			ans += upcnt * downcnt;
			upcnt = 0, downcnt = 0;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}