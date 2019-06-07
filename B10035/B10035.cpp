#include <iostream>
#include <string>
using namespace std;
int getlen(long long n) {
	int cnt = 0;
	while (n) {
		++cnt;
		n /= 10;
	}
	return cnt;
}
long long tonum(const string& s) {
	int len = s.length();
	long long num = 0;
	for (int i = 0; i < len; ++i) {
		num *= 10;
		num += (s[i] - '0');
	}
	return num;
}
int main() {
	long long x, y; cin >> x >> y;
	int a = getlen(x);
	int b = getlen(y);
	long long ans = 0;
	for (int len = a; len <= b; ++len) {
		for (int num = 0; num <= 9; ++num) {
			string s(len, '0' + num);
			for (int change = 0; change <= 9; ++change) {
				if (num != change) {
					for (int pos = 0; pos < len; ++pos) {
						s[pos] = change + '0';
						long long k = tonum(s);
						if (s[0]!='0' && k >= x && k <= y) ++ans;
						s[pos] = num + '0';
					}
				}
			}
		}
	}
	cout << ans << '\n';
}