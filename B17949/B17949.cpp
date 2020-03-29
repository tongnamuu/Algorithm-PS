#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long to_num(const string& s) {
	int len = s.length();
	long long ans = 0;
	for (int i = 0; i < len; ++i) {
		char x = s[i];
		ans *= 16LL;
		if ('x' >= 0 && x <= '9') ans += x - '0';
		else ans += x - 'a' + 10;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int n; cin >> n;
	int prev = 0;
	for (int i = 0; i < n; ++i) {
		string c; cin >> c;
		if (c == "char") {
			cout << to_num(s.substr(prev, 2)) << ' ';
			prev += 2;
		}
		else if (c == "int") {
			cout << to_num(s.substr(prev, 8)) << ' ';
			prev += 8;
		}
		else if (c == "long_long") {
			cout << to_num(s.substr(prev, 16)) << ' ';
			prev += 16;
		}
	}
}