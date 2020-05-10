#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007
long long cnt[4];
long long getValue(long long n) {
	long long ans = 1;
	long long val = n;
	for (long long i = n - 1; i >= 0; --i) {
		ans += val;
		val *= i;
		ans %= MOD;
		val %= MOD;
	}
	return ans;
}
int check(const string& s) {
	int len = s.length();
	bool nf = false, cf = false, nc = false, cn = false;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'N') {
			nf = true;
			if (cf) {
				cn = true;
			}
		}
		else if (s[i] == 'C') {
			cf = true;
			if (nf) {
				nc = true;
			}
		}
	}
	if (nc) return 3;
	else if (cn) return 2;
	else if (cf) return 1;
	else if (nf) return 0;
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		cnt[check(s)]++;
	}
	long long temp = (getValue(cnt[0])*getValue(cnt[1])) % MOD;
	temp *= (cnt[2] + 1);
	temp %= MOD;
	long long ans = (getValue(n) + MOD - temp) % MOD;
	cout << ans;
}