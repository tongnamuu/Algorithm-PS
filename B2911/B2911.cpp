#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int>a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	long long ans = a[0].second;
	int prev = a[0].second;
	for (int i = 1; i < n; ++i) {
		if (a[i].second > prev) {
			ans += (long long)(a[i].second - prev);
		}
		prev = a[i].second;
	}
	cout << ans << '\n';
}