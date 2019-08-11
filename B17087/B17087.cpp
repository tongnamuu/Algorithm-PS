#include <iostream>
using namespace std;
int a[100001];
int abs(int x, int y) { return x > y ? x - y : y - x; }
int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, s; cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = abs(a[i], s);
	}
	int ans = a[0];
	for (int i = 1; i < n; ++i) {
		ans = gcd(ans, a[i]);
	}
	cout << ans << '\n';
}