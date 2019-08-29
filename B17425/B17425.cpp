#include <iostream>
using namespace std;
long long d[1000001];
long long sum[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 1000000; ++i) d[i] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		for (int j = 2; i*j <= 1000000; ++j) {
			d[i*j] += j;
		}
	}
	for (int i = 1; i <= 1000000; ++i) {
		sum[i] = sum[i - 1] + d[i];
	}
	int T; cin >> T;
	while (T--) {
		int n; cin >> n; cout << sum[n] << '\n';
	}
}