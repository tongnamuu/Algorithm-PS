#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long getnum2(const string& s) {
	int len = s.length();
	long long ans = 0;
	for (int i = 0; i < len; ++i) {
		ans <<= 1;
		ans += (s[i] - '0');
	}
	return ans;
}
string getnum3(long long num) {
	string temp;
	if (num == 0) return "0";
	while (num) {
		temp += (char)((num % 3) + '0');
		num /= 3;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
bool ok(const string&s, const string& b) {
	int a = s.length(), blen = b.length();
	if (a != blen) return false;
	int cnt = 0;
	for (int i = 0; i < a; ++i) {
		if (s[i] != b[i]) ++cnt;
	}
	if (cnt == 1) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		string a, b; cin >> a >> b;
		int lena = a.length(), lenb = b.length();
		long long temp = getnum2(a);
		for (long long i = 1, cnt = 0; cnt < lena; i *= 2, ++cnt) {
			string t = getnum3(temp^i);
			if (ok(t, b)) {
				cout << '#' << test_case << ' ' << (temp ^ i) << '\n';
				break;
			}
		}
	}
}