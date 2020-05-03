#include <iostream>
#include <algorithm>
using namespace std;
#define N 250001
int a[N];
int r[N];
int l[N];
int get_score(int a, int b, long long c) {
	if (a > b) return c - a + b;
	return b - a;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n; long long c; cin >> n >> c;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	long long rv = 0;
	long long lv = 0;
	for (int i = 1; i < n; ++i) {
		r[i] = get_score(a[i], a[i + 1], c);
		l[i] = get_score(a[i + 1], a[i], c);
		rv += r[i];
	}
	long long ans = rv;
	int button = 1;
	for (int i = 2; i <= n; ++i) {
		rv -= r[i - 1];
		lv += l[i - 1];
		long long temp = max(rv, lv);
		if (temp < ans) {
			ans = temp;
			button = i;
		}
	}
	cout << button << '\n' << ans;
}