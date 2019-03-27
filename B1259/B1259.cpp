#include <iostream>
#include <string>
using namespace std;
bool check(const string &s) {
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (s[i] != s[len - 1 - i]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (1) {
		string s;
		cin >> s;
		if (s == "0") break;
		if (check(s)) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}