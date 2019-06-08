#include <iostream>
using namespace std;
int a[1001];
int d[1001];
int max(int a, int b) { return a > b ? a : b; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = 1;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		d[i] = 1;
		for (int j = 0; j < i; ++j) {
			if(a[i]>a[j]) d[i] = max(d[i], d[j] + 1);
		}
		ans = max(ans, d[i]);
	}
	cout << ans << '\n';
}