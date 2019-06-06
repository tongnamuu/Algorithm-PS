#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	long long r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long a, b; cin >> a >> b;
	long long ans = gcd(a, b);
	for (long long i = 0; i < ans; ++i) cout << 1;
}