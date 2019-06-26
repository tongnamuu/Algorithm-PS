#include <iostream>
using namespace std;
int getlen(long long n) {
	if (n == 0) return 1;
	int cnt = 0;
	while (n) {
		n /= 10;
		++cnt;
	}
	return cnt;
}
bool check(long long n) {
	int cnt = 0;
	int len = getlen(n);
	while (n % 5 == 0) {
		n /= 5;
		++cnt;
	}
	return len >= cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		if (n == 1) {
			cout << '#' << test_case << ' ' << 1 << '\n';
			continue;
		}
		int len = getlen(n);
		long long num = 1LL;
		int cnt = 2;
		for (int i = 1; i <= len; ++i) {
			num *= 5LL;
			long long x = num;
			for (int j = 0; j <= i + 1; ++j) {
				if (x>n) break;
				if (check(x)) ++cnt;
				x *= 2LL;
			}
		}
		cout << '#' << test_case << ' ' << cnt << '\n';
	}
}