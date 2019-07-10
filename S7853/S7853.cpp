#include <iostream>
#include <string>
using namespace std;
string s;
int len;
const int MOD = 1000000007;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case) {
		cin >> s;
		len = s.length();
		if (len == 1) {
			cout << '#' << test_case << ' ' << 1 << '\n';
			continue;
		}
		else if (len == 2) {
			if (s[0] == s[1])cout << '#' << test_case << ' ' << 1 << '\n';
			else cout << '#' << test_case << ' ' << 4 << '\n';
			continue;
		}
		else {
			long long start = 1;
			if (s[0] != s[1]) start = 2;
			for (register int i = 1; i < len - 1; ++i) {
				if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1]) start *= 3;
				else if (s[i - 1] == s[i] && s[i] == s[i + 1]) start = start;
				else start *= 2;
				start %= MOD;
			}
			if (s[len - 2] != s[len - 1]) start *= 2;
			start %= MOD;
			cout << '#' << test_case << ' ' << start << '\n';
		}
	}
}