#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define INITIAL_VALUE 98765432123456LL
#define MOD 1000000009
long long seed = INITIAL_VALUE;
vector<long long>ans;
long long myabs(long long x) { return x > 0 ? x : -x; }
long long myrand() {
	seed += 33567323LL;
	seed %= MOD;
	seed *= 4LL;
	seed %= MOD;
	return seed;
}
long long mul(long long a, long long b, long long c) {
	long long x = 0, y = a % c;
	while (b) {
		if (b % 2) x = (x + y) % c;
		y = (y + y) % c;
		b >>= 1;
	}
	return x % c;
}
long long llpow(long long a, long long b, long long c) {
	long long x = 1;
	while (b) {
		if (b & 1) {
			x = mul(x, a, c);
		}
		a = mul(a, a, c);
		b >>= 1;
	}
	return x;
}
long long gcd(long long a, long long b) {
	while (b) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}
bool withness(long long a, long long n) {
	long long m = n - 1;
	int cnt = 0;
	while (!(m & 1)) {
		++cnt;
		m /= 2;
	}
	long long x = llpow(a, m, n);
	long long pre = x;
	for (int i = 0; i < cnt; ++i) {
		x = mul(x, x, n);
		if (x == 1 && pre != 1 && pre != n - 1) return true;
		pre = x;
	}
	return x != 1;
}
bool isPrime(long long n) {
	if (n == 1) return false;
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19) return true;
	for (int i = 0; i < 20; ++i) {
		long long temp = rand() % n;
		while (temp == 0) temp = rand() % n;
		bool flag = withness(temp, n);
		if (flag) return false;
	}
	return true;
}

void pollard_rho(long long n) {
	if (isPrime(n)) {
		ans.push_back(n);
		return;
	}
	int i = 0, k = 2;
	long long x = INITIAL_VALUE, y = x;
	long long d = n;
	while (1) {
		i++;
		x = (mul(x, x, n) + n - 1) % n;
		d = gcd(myabs(y - x), n);
		if (d != 1) break;
		if (i == k) {
			y = x;
			k *= 2;
		}
	}
	if (d != n) {
		pollard_rho(d);
		pollard_rho(n / d);
		return;
	}
	if (!(n & 1)) {
		pollard_rho(2);
		pollard_rho(d / 2);
		return;
	}
	for (long long i = 3; i*i <= n; i += 2) {
		if (n%i == 0) {
			pollard_rho(i);
			pollard_rho(d / i);
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long n; cin >> n;
	pollard_rho(n);
	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << '\n';
}