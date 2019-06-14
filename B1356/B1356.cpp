#include <iostream>
#include <string>
using namespace std;
string s;
bool solve() {
	int len = s.length();
	long long first = s[0] - '0';
	long long second = 1;
	for (int i = 1; i < len; ++i) {
		second *= (s[i] - '0');
	}
	if (first == second) return true;
	for (int i = 1; i < len - 1; ++i) {
		int temp = s[i] - '0';
		first *= temp;
		second /= temp;
		if (first == second) return true;
	}
	return false;
}
int main() {
	cin >> s;
	if (s == "1") {
		cout << "NO" << '\n';
	}
	else {
		int cnt = 0;
		for (int i = 0; s[i]; ++i) {
			cnt += (s[i] == '0');
		}
		if (cnt >= 2) cout << "YES" << '\n';
		else if (cnt == 1) cout << "NO" << '\n';
		else cout << (solve() ? "YES" : "NO");
	}
}