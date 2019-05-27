#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int now = a[i];
		int cnt = 0;
		for (int j = i; j < n; ++j) {
			if (a[j] > a[i] + k) break;
			++cnt;
		}
		if (cnt > ans) ans = cnt;
	}
	cout << ans << '\n';
}