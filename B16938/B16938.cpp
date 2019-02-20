#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, l, r, c;
	cin >> n >> l >> r >> c;
	int a[16];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int cnt = 0;
		int sum = 0;
		int min = 10000000;
		int max = 0;
		for (int j = 0; j < n; ++j) {
			if (i&(1 << j)) {
				cnt++;
				sum += a[j];
				if (min > a[j]) min = a[j];
				if (max < a[j]) max = a[j];
			}
		}
		if (cnt >= 2) {
			if (sum >= l && sum <= r && max - min >= c)
				ans++;
		}
	}
	cout << ans << '\n';
}