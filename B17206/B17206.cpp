#include <iostream>
using namespace std;
long long d1[80001];
long long d2[80001];
long long d3[80001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 3; i <= 80000; i += 3) {
		d1[i] = d1[i - 3] + i;
	}
	for (int i = 7; i <= 80000; i += 7) {
		d2[i] = d2[i - 7] + i;
	}
	for (int i = 21; i <= 80000; i += 21) {
		d3[i] = d3[i - 21] + i;
	}
	int T; cin >> T;
	for (int i = 0,n; i < T; ++i) {
		cin >> n;
		int a = n - n % 3;
		int b = n - n % 7;
		int c = n - n % 21;
		cout << d1[a] + d2[b] - d3[c] << '\n';
	}
}