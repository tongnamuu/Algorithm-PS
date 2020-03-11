#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int b[10001];
int c[10001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i - 1] && a[i]) {
			b[i] = min(a[i - 1], a[i]);
			a[i - 1] -= b[i];
			a[i] -= b[i];
		}
		if (a[i] && b[i - 1]) {
			c[i] = min(a[i], b[i - 1]);
			a[i] -= c[i];
			b[i - 1] -= c[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (a[i] * 3 + b[i] * 5 + c[i] * 7);
	}
	cout << ans;
}