#include <iostream>
using namespace std;
long long d[31];
long long t[31];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	t[1] = 1LL; t[2] = 3LL;
	for (int i = 3; i <= n; ++i) {
		t[i] = t[i - 1] + t[i - 2] * 2LL;
	}
	d[1] = 1;
	d[2] = 3;
	if (n > 2) {
		if (n & 1) {
			d[n] = t[n] + t[(n - 1) / 2];
		}
		else {
			d[n] = t[n] + t[n / 2] + t[(n - 2) / 2] * 2LL;
		}
		d[n] >>= 1;
	}
	cout << d[n];
}