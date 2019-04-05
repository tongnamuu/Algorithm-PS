#include <iostream>
#include <string>
using namespace std;
long long tonum(const string& s, int len) {
	long long num = 0;
	for (int i = 0; i < len; ++i) {
		num *= 10;
		num += (s[i] - '0');
	}
	return num;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		string s;  cin >> s;
		int len = s.length();
		for (int i = len - 2; i >= 0; --i) {
			if (s[i] > s[i + 1]) {
				s[i] -= 1;
				for (int j = i + 1; j < len; ++j) {
					s[j] = '9';
				}
			}
		}
		long long ans = tonum(s, len);
		cout << "Case #" << tc << ": " << ans << '\n';
	}
}