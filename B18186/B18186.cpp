#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000001
long long a[N];
long long b[N];
long long c[N];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	long long B, C; cin >> B >> C;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (C < B) {
			if (a[i - 1] && a[i]) {
				b[i] = min(a[i - 1], a[i]);
				a[i - 1] -= b[i];
				a[i] -= b[i];
			}
			if (b[i - 1] && a[i]) {
				c[i] = min(b[i - 1], a[i]);
				b[i - 1] -= c[i];
				a[i] -= c[i];
			}
		}
	}
	long long ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		ans += (a[i] * B);
		ans += (b[i] * (B + C)); 
		ans += (c[i] * (B + C + C)); 
	}
	cout << ans;
}