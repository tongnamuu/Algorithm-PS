#include <iostream>
#include <string>
using namespace std;
int getnum(const string &s) {
	int ans = 0;
	for (int i = 0; i < 3; ++i) ans += (s[i] - '0') << (2 - i);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int len = s.length();
	int c = len % 3;
	if (c) {
		c = 3 - c;
		len += c;
		while (c--) {
			s = '0' + s;
		}
	}
	for (int i = 0; i < len; i += 3) cout << getnum(s.substr(i, 3));
}