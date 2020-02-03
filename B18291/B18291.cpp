#include <iostream>
using namespace std;
#define MOD 1000000007
int pow(int n) {
	if (n == -1 || n == 0) return 1;
	long long val = 1LL;
	long long p = 2LL;
	while (n) {
		if (n & 1) val *= p, val %= MOD;
		p *= p;
		p %= MOD;
		n >>= 1;
	}
	return val;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << pow(n - 2) << '\n';
	}
}