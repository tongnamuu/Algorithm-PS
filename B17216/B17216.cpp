#include <iostream>
using namespace std;
int a[1001];
int d[1001];
int max(int a, int b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; d[i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (a[j] > a[i]) d[i] = max(d[i], d[j] + a[i]);
		}
	}
	int ans = a[0];
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, d[i]);
	}
	cout << ans;
}